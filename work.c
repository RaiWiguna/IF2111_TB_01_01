#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "work.h"
#include "mesinkata.h"

void sleep(int second) {
    time_t start_time = time(NULL); // Waktu mulai
    time_t end_time = start_time + second; // Waktu akhir

    while (time(NULL) < end_time) {
        // Loop sampai waktu sekarang melebihi waktu akhir
    }
}

Job jobList[] = {
    {"Evil Lab Assistant", 100, 14},
    {"OWCA Hiring Manager", 4200, 21},
    {"Cikapundunginator Caretaker", 7000, 30},
    {"Mewing Specialist", 10000, 22},
    {"Inator Connoisseur", 997, 15}
};

int jobCount = 5;

void Work(User *u) {

    // Menampilkan daftar pekerjaan
    printf("Daftar Pekerjaan:\n");
    for(int i = 0; i < jobCount; i++) {
        printf("%d. %s (pendapatan=%d, durasi=%ds)\n", i+1, jobList[i].name, jobList[i].income, jobList[i].duration);
    }

    // Input untuk memilih pekerjaan
    printf("\nMasukkan pekerjaan yang dipilih: ");
    STARTWORD();

    // Membuat variabel untuk menentukan mana perkerjaan yang dipilih
    int angkapilihan;
    if(IsSame(CurrentWord.TabWord,"Evil Lab Assistant")) {
        angkapilihan = 0;
    } else if (IsSame(CurrentWord.TabWord,"OWCA Hiring Manager"))
    {
        angkapilihan = 1;
    } else if (IsSame(CurrentWord.TabWord,"Cikapundunginator Caretaker"))
    {
        angkapilihan = 2;
    } else if (IsSame(CurrentWord.TabWord, "Mewing Specialist"))
    {
        angkapilihan = 3;
    } else if (IsSame(CurrentWord.TabWord,"Inator Connoisseur"))
    {
        angkapilihan = 4;
    }

    printf("\nAnda sedang bekerja sebagai %s... harap tunggu.\n", jobList[angkapilihan].name);

    // Pekerjaan diproses
    for (int i = 0; i < jobList[angkapilihan].duration; i++) {
        sleep(1);
    }

    // Pekerjaan selesai
    printf("\nPekerjaan selesai! +%d rupiah telah ditambahkan ke akun Anda.\n", jobList[angkapilihan].income);

    // Income pekerjaan dimasukkan kedalam user money
    u->money += jobList[angkapilihan].income;
}