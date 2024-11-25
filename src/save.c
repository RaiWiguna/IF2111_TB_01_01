#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"
#include "listlinear.h"

void SAVE(char *namafile, TabInt T) {
    FILE *file;
    char path[100] = "./save/"; 
    int i = 0;

    while (namafile[i] != '\0') {
        path[7 + i] = namafile[i];  
        i++;
    }
    path[7 + i] = '\0';

    printf("Path file: %s\n", path);

    file = fopen(path, "r");
    if (file != NULL) {
        fclose(file);  
        printf("File '%s' sudah ada. Apakah Anda ingin menimpa? (y/n): ", namafile);
        
        STARTWORD_ITEM(stdin); 

        printf("Input yang dibaca: %s\n", CurrentWord1.TabWord);

        if (EndWord || CurrentWord1.Length == 0 || CurrentWord1.TabWord[0] != 'y') {
            printf("Proses penyimpanan dibatalkan.\n");
            return; 
        }
    }

    file = fopen(path, "w");
    if (file == NULL) {
        printf("Error: Tidak dapat membuka file '%s' untuk menulis.\n", namafile);
        return; 
    }

    for (IdxType i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        fprintf(file, "%d\n", T[i]);
    }

    fclose(file);
    printf("Save file berhasil disimpan.\n");
}

int main() {
    TabInt T;
    MakeEmpty(&T);


    for (int i = 1; i <= 5; i++) {
        SetEl(&T, i, i * 10);  
        SetNeff(&T, i);
    }

    printf("Masukkan nama file untuk menyimpan data: \n");

    char filename[100];
    int i = 0;

    START();  
    while (currentChar != '\n' && currentChar != MARK) {
        filename[i] = currentChar;  
        i++;
        ADV();  
    }
    filename[i] = '\0';  

    printf("Nama file yang dimasukkan: %s\n", filename);

    SAVE(filename, T);

    return 0;
}
