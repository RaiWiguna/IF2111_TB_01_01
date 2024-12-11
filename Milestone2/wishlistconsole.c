#include "wishlistconsole.h"
#include "string.h"
#include <stdlib.h>
#include <stdio.h>

void wishlistAdd(LinkedList *L) {
    char* item;

    printf("Masukkan nama barang: ");
    STARTWORD();
    item = CurrentWord.TabWord;

    Address temp = FirstL(*L);

    // Cari apakah barang sudah ada di wishlist
    while (temp != NIL) {
        if (strcmp_custom(InfoL(temp), item) == 0) {
            printf("%s sudah ada di wishlist!\n", item);
            return;
        }
        temp = NextL(temp);
    }

    // Jika barang belum ada, tambahkan ke wishlist
    Address newElement = Allocate(item); // Alokasikan memori untuk elemen baru
    if (newElement != NIL) {
        InsertLastL(L, newElement);
        printf("Berhasil menambahkan %s ke wishlist!\n", item);
    } else {
        printf("Gagal menambahkan %s ke wishlist (memori penuh)!\n", item);
    }
}

void wishlistSwap(LinkedList *L, int i, int j) {
    if (i == j) {
        printf("Gagal menukar posisi, posisi ke-%d dan ke-%d adalah sama.\n", i, j);
        return;
    }

    Address Pi = FirstL(*L), Pj = FirstL(*L);
    int index = 1;

    // Cari elemen ke-i dan ke-j
    while (Pi != NIL && index < i) {
        Pi = NextL(Pi);
        index++;
    }
    index = 1;
    while (Pj != NIL && index < j) {
        Pj = NextL(Pj);
        index++;
    }

    if (Pi == NIL || Pj == NIL) {
        printf("Gagal menukar posisi! Salah satu indeks tidak valid.\n");
    } else {
        ElementType temp = strdup(InfoL(Pi));
        free(InfoL(Pi));
        InfoL(Pi) = strdup(InfoL(Pj));
        free(InfoL(Pj));
        InfoL(Pj) = temp;

        printf("Berhasil menukar posisi %s dengan %s pada wishlist!\n", InfoL(Pi), InfoL(Pj));
    }
}

void wishlistRemoveNumber(LinkedList *L, int index) {
    if (IsListEmpty(*L)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    Address P = FirstL(*L);
    int currentIndex = 1;

    // Cari elemen di posisi index
    while (P != NIL && currentIndex < index) {
        P = NextL(P);
        currentIndex++;
    }

    if (P == NIL) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", index);
    } else {
        printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", index);
        if (P == FirstL(*L)) {
            DeleteFirstL(L, &P);
        } else if (P == LastL(*L)) {
            DeleteLastL(L, &P);
        } else {
            NextL(PrevL(P)) = NextL(P);
            PrevL(NextL(P)) = PrevL(P);
        }
        Deallocate(P);
    }
}

void wishlistRemove(LinkedList *L) {
    char* item;

    printf("Masukkan nama barang yang akan dihapus: ");
    STARTWORD();
    item = CurrentWord.TabWord;

    Address temp = FirstL(*L);

    // Cari elemen berdasarkan item
    while (temp != NIL) {
        if (strcmp_custom(InfoL(temp), item) == 0) {
            // Hapus elemen dari list
            if (temp == FirstL(*L)) {
                DeleteFirstL(L, &temp);
            } else if (temp == LastL(*L)) {
                DeleteLastL(L, &temp);
            } else {
                NextL(PrevL(temp)) = NextL(temp);
                PrevL(NextL(temp)) = PrevL(temp);
            }
            printf("%s berhasil dihapus dari WISHLIST!\n", item);
            Deallocate(temp); // Dealokasi memori
            return;
        }
        temp = NextL(temp);
    }

    // Jika barang tidak ditemukan
    printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", item);
}

void wishlistClear(LinkedList *L) {
    Address P;
    while (!IsListEmpty(*L)) {
        DeleteFirstL(L, &P);
        Deallocate(P);
    }
    printf("Wishlist telah dikosongkan.\n");
}

void wishlistShow(LinkedList L) {
    if (IsListEmpty(L)) {
        printf("Wishlist kamu kosong!\n");
    } else {
        printf("Berikut adalah isi wishlist-mu:\n");
        Address P = FirstL(L);
        int index = 1;
        while (P != NIL) {
            printf("%d. %s\n", index, InfoL(P));
            P = NextL(P);
            index++;
        }
    }
}