#include <stdio.h>
#include "quit.h"
#include "mesinkarakter.h"
#include "save.h"

void quit(boolean *status, TabInt T){
    int len = 0; 
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");

    START();
    printf("\n");

    if (CC == 'Y' || CC == 'y'){
        char file[1000];
        printf("Menyimpan ke file: ");
        ADV();
        while (CC != MARK && len < 1000){
            file[len] = CC;
            len++;
            ADV();
        }
        if (len == 0){
            printf("Nama file kosong. Penyimpanan dibatalkan. \n");
        }
        else{
            printf("'%.*s'\n", len, file);
            SAVE(file, T);
            printf("Sesi berhasil disimpan!\n");
        }
    }

    else if(CC == 'N' || CC == 'n'){
        printf("\nAman aja. Kamu bisa menyimpannya lain kali. \n");
    }
    else{
        printf("\nOops! Sepertinya input kurang tepat. Data tidak disimpan.\n");
    }

    printf("Terima kasih sudah menggunakan PURRMART.\n ");
    printf("See you next time! ^_^\n");

}