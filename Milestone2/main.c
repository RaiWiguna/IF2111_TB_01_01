#include <stdio.h>
#include <stdlib.h>
#include "wishlistconsole.h" // Header untuk fungsi wishlist

void printMenu() {
    printf("===== MENU WISHLIST =====\n");
    printf("1. Tambahkan barang ke wishlist (WISHLIST ADD)\n");
    printf("2. Menukar isi barang (WISHLIST SWAP)\n");
    printf("3. Hapus barang dari wishlist berdasarkan nama (WISHLIST REMOVE)\n");
    printf("4. Hapus barang dari wishlist berdasarkan index (WISHLIST REMOVE BY INDEX)\n");
    printf("5. Tampilkan isi wishlist (WISHLIST SHOW)\n");
    printf("6. Kosongkan wishlist (WISHLIST CLEAR)\n");
    printf("7. Keluar\n");
    printf("=========================\n");
    printf("Masukkan pilihan: ");
}

int main() {
    LinkedList wishlist;
    CreateList(&wishlist); // Inisialisasi wishlist kosong

    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        getchar(); // Membersihkan buffer setelah scanf

        switch (choice) {
            case 1:
                // Tambahkan barang ke wishlist
                wishlistAdd(&wishlist);
                break;

            case 2:
                // Menukar isi barang
                int i, j;
                STARTWORD();
                i = atoi(CurrentWord.TabWord);
                STARTWORD();
                j = atoi(CurrentWord.TabWord);
                wishlistSwap(&wishlist, i, j);
                break;

            case 3:
                // Hapus barang berdasarkan nama
                wishlistRemove(&wishlist);
                break;

            case 4:
                // Hapus barang berdasarkan index
                int index;
                STARTWORD();
                index = atoi(CurrentWord.TabWord);
                wishlistRemoveNumber(&wishlist, index);
                break;

            case 5:
                // Tampilkan isi wishlist
                wishlistShow(wishlist);
                break;

            case 6:
                // Kosongkan wishlist
                wishlistClear(&wishlist);
                break;

            case 7:
                printf("Terima kasih telah menggunakan program wishlist!\n");
                break;

            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 7);

    return 0;
}
