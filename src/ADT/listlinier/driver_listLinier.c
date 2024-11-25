#include <stdio.h>
#include "listlinier.h"

int main() {
    List L1, L2, L3;

    printf("--- Membuat List Kosong ---\n");
    L1 = MakeList();
    printf("Apakah L1 kosong? %s\n", IsEmpty(L1) ? "Ya" : "Tidak");

    printf("--- Menambahkan Elemen ---\n");
    InsertFirst(&L1, 1);
    InsertLast(&L1, 2);
    InsertAt(&L1, 3, 1); 
    printf("Isi L1: ");
    for (int i = FirstIdx(L1); i <= LastIdx(L1); i++) {
        printf("%d ", Get(L1, i));
    }
    printf("\n");

    printf("--- Menghapus Elemen ---\n");
    DeleteFirst(&L1);
    printf("Isi L1 setelah menghapus elemen pertama: ");
    for (int i = FirstIdx(L1); i <= LastIdx(L1); i++) {
        printf("%d ", Get(L1, i));
    }
    printf("\n");

    DeleteAt(&L1, 0);  
    printf("Isi L1 setelah menghapus elemen di indeks 0: ");
    for (int i = FirstIdx(L1); i <= LastIdx(L1); i++) {
        printf("%d ", Get(L1, i));
    }
    printf("\n");

    DeleteLast(&L1);
    printf("Isi L1 setelah menghapus elemen terakhir: ");
    for (int i = FirstIdx(L1); i <= LastIdx(L1); i++) {
        printf("%d ", Get(L1, i));
    }
    printf("\n");

    printf("---Panjang List ---\n");
    printf("Panjang L1: %d\n", Length(L1));

    printf("--- Validasi Indeks ---\n");
    printf("Apakah indeks 0 valid? %s\n", IsIdxValid(L1, 0) ? "Ya" : "Tidak");
    printf("Apakah indeks 0 efektif? %s\n", IsIdxEff(L1, 0) ? "Ya" : "Tidak");

    printf("--- Pencarian Elemen ---\n");
    InsertFirst(&L1, 4);
    InsertLast(&L1, 5);
    printf("Apakah elemen 4 ada? %s\n", Search(L1, 10) ? "Ya" : "Tidak");
    printf("Apakah elemen 5 ada? %s\n", Search(L1, 30) ? "Ya" : "Tidak");

    printf("--- Penggabungan List ---\n");
    L2 = MakeList();
    InsertLast(&L2, 6);
    InsertLast(&L2, 7);
    printf("Isi L2: ");
    for (int i = FirstIdx(L2); i <= LastIdx(L2); i++) {
        printf("%d ", Get(L2, i));
    }
    printf("\n");

    L3 = Concat(L1, L2);
    printf("Isi L3 setelah penggabungan L1 dan L2: ");
    for (int i = FirstIdx(L3); i <= LastIdx(L3); i++) {
        printf("%d ", Get(L3, i));
    }
    printf("\n");

    return 0;
}
