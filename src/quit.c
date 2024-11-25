#include <stdio.h>
#include "quit.h"
#include "mesinkarakter.h"
#include "save.h"
#include "listlinear.h"

void QUIT(boolean *status, TabInt T){
    int len = 0; 
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");

    START();
    printf("\n");

    if (currentChar == 'Y' || currentChar == 'y'){
        char file[1000];
        printf("Menyimpan ke file: ");
        ADV();
        while (currentChar != MARK && len < 1000){
            file[len] = currentChar;
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

    else if(currentChar == 'N' || currentChar == 'n'){
        printf("\nAman aja. Kamu bisa menyimpannya lain kali. \n");
    }
    else{
        printf("\nOops! Sepertinya input kurang tepat. Data tidak disimpan.\n");
    }

    printf("Terima kasih sudah menggunakan PURRMART.\n ");
    printf("See you next time! ^_^\n");

}