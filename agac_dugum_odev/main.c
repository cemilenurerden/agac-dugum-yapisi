#include <stdio.h>
#include <stdlib.h>

struct Dugum {  //struct yap�s� ac�p icerisinde degiskenleri tanimladim
    int veri;
    struct Dugum* sol; //sol dugumun adresini tutacak degisken tanimladim
    struct Dugum* sag; //sag dugumun adresini tutacak degisken tanimladim
};

int kokDugum(struct Dugum* dugum) {  // int turunde bir fonksiyon tanimladim ve parametre olarak dugum adresini tutacak degiken tan�mlad�m
    int sol_veri = 0, sag_veri = 0;  //degisken tanimlayip 0 a atadim.

    if (dugum == NULL || (dugum->sol == NULL && dugum->sag == NULL)) //eger dugum veya dugumun sol tarafi veya sag tarafi bo�sa
        return 1; // return 1 dondurdum

    else {
        if (dugum->sol != NULL) //eger dugumun sol taraf� bos degilse
            sol_veri = dugum->sol->veri; //sol dugumden veri alinir ve sol_veri adli veriye atadim

        if (dugum->sag != NULL)  //eger dugumun sag taraf� bos degilse
            sag_veri = dugum->sag->veri; //sag dugumden veri alinir ve sag_veri adli veriye atadim

        if ((dugum->veri == sol_veri + sag_veri) && kokDugum(dugum->sol) && kokDugum(dugum->sag))//e�er sol_veri ve sag_veri toplami ana d���m�n verisine e�itse ve sol ve sa� taraflardaki d���mler de kok d���m �zelli�ine sahiplerse
            return 1; // dondurur
        else
            return 0; // degilse 0 dondurur
    }
}


struct Dugum* yeni_dugum(int veri) {  // yeni dugum adli fonksiyon tanimladim veri adinda yeni bir degisken tanimladim
    struct Dugum* dugum = (struct Dugum*) malloc(sizeof(struct Dugum));
    dugum->veri = veri; //yeni bir d���m olu�turdum ve verilen de�eri d���m�n verisi olarak atadim
    dugum->sol = NULL; //sol ve
    dugum->sag = NULL;// sag dugumleri bos atadim

    return dugum; //dugumun isaretcisini geri dondurdum
}

int main() {
    struct Dugum* kok = yeni_dugum(18); // kok adinda degiskene yeni_dugum adindaki fonksiyonu cagirarak 18 degerini atadim
    kok->sol =yeni_dugum(13); // kokun sol dugumune fonksiyon cag�rarak 13 atadim
    kok->sag = yeni_dugum(6); //kokun sag dugumune fonksiyon cag�rarak 5 atadim


    if (kokDugum(kok)) // kok , kokDugum fonksiyonuna gonderilir ve  alt d���mlerin toplam�n�n kok d���m�n verisine e�it olup olmad��� kontrol edilir
        printf("Alt dugumlerin toplami kok degerine esittir.");  //eger dogruysa, yazdirdim
    else
        printf("Alt d���mlerin toplami kok degerine esit degildir."); // yanlissa, yazdirdim

    return 0;
}
