#include <stdio.h>
#include <stdlib.h>
#include "wishlistconsole.h" // Header untuk fungsi wishlist

void printMenu() {
    printf("===== MENU WISHLIST =====\n");
    printf("1. Tambahkan barang ke wishlist (WISHLIST ADD)\n");
    printf("2. Hapus barang dari wishlist berdasarkan nama (WISHLIST REMOVE)\n");
    printf("3. Tampilkan isi wishlist (WISHLIST SHOW)\n");
    printf("4. Kosongkan wishlist (WISHLIST CLEAR)\n");
    printf("5. Keluar\n");
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
                // Hapus barang berdasarkan nama
                wishlistRemove(&wishlist);
                break;

            case 3:
                // Tampilkan isi wishlist
                wishlistShow(wishlist);
                break;

            case 4:
                // Kosongkan wishlist
                wishlistClear(&wishlist);
                break;

            case 5:
                printf("Terima kasih telah menggunakan program wishlist!\n");
                break;

            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 5);

    // Membersihkan memory yang digunakan oleh wishlist sebelum keluar
    wishlistClear(&wishlist);

    return 0;
}
