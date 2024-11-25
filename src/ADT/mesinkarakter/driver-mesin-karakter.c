#include <stdio.h>
#include "mesinkarakter.h"

int main() {
    char x;
    FILE *file;  // Menambahkan pointer FILE untuk membuka file

    printf("TEST UNTUK MENULISKAN KARAKTER\n");
    printf("TULISKAN KARAKTER : ");
    START();
    while(!IsEOP()) { // Diakhiri dengan ENTER
        x = GetCC();
        printf("%c\n", x);
        ADV();
    }

    printf("\nTEST UNTUK MELAKUKAN AKUISISI FILE\n");
    // Membuka file dengan fopen(), lalu memberikan pointer file ke START_File
    file = fopen("driver.txt", "r");
    if (file == NULL) {  // Pastikan file berhasil dibuka
        printf("File tidak ditemukan.\n");
        return 1;  // Menghentikan program jika file tidak ditemukan
    }
    START_File(file);  // Menggunakan pointer file
    while(!IsEOP()) {
        x = GetCC();
        printf("%c", x);
        ADV_File();
    }
    printf("\n");

    fclose(file);  // Jangan lupa untuk menutup file setelah selesai digunakan

    return 0;
}
