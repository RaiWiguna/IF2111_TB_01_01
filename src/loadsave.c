#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "mesinkata.h"
#include "array.h"

void LOAD(char *filename, TabInt *T) {
    FILE *file;
    char path[100] = "./save/"; // Folder tempat save file
    int idx = 0;

    // Membuat path lengkap
    while (filename[idx] != '\0') {
        path[7 + idx] = filename[idx];
        idx++;
    }
    path[7 + idx] = '\0';

    file = fopen(path, "r");
    if (file == NULL) {
        printf("Error: Save file '%s' tidak ditemukan. Pastikan nama file benar.\n", filename);
        return;
    }

    MakeEmpty(T); // Inisialisasi list kosong

    STARTWORD();
    while (!EndWord) {
        int item;
        if (sscanf(CurrentWord.TabWord, "%d", &item) == 1) { // Validasi konversi
            if (NbElmt(*T) < IdxMax) {
                // Cek apakah item sudah ada di dalam list (hindari duplikasi)
                boolean isDuplicate = false;
                for (IdxType i = GetFirstIdx(*T); i <= NbElmt(*T); i++) {
                    if (GetElmt(*T, i) == item) {
                        isDuplicate = true;
                        break;
                    }
                }
                if (!isDuplicate) {
                    SetEl(T, NbElmt(*T) + 1, item); // Masukkan item ke list
                    SetNeff(T, NbElmt(*T) + 1);
                }
            } else {
                printf("Warning: Data di file melebihi kapasitas maksimum (%d elemen). Data tambahan diabaikan.\n", IdxMax);
                break; // Berhenti jika kapasitas maksimum tercapai
            }
        } else {
            printf("Error: Format file tidak valid. Data '%s' diabaikan.\n", CurrentWord.TabWord);
        }
        ADVWORD();
    }

    fclose(file);

    if (NbElmt(*T) == 0) {
        printf("Warning: File kosong, tidak ada data yang dimuat.\n");
    } else {
        printf("Save file berhasil dibaca. Data berhasil dimuat ke program.\n");
    }
}

void SAVE(char *filename, TabInt T) {
    FILE *file;
    char path[100] = "./save/";
    int idx = 0;

    // Membuat path lengkap
    while (filename[idx] != '\0') {
        path[7 + idx] = filename[idx];
        idx++;
    }
    path[7 + idx] = '\0';

    // Cek apakah folder save ada, jika tidak buat folder secara manual
    if (system("mkdir -p ./save") != 0) {
        printf("Error: Tidak dapat membuat folder 'save'.\n");
        return;
    }

    // Cek apakah file sudah ada
    file = fopen(path, "r");
    if (file != NULL) {
        fclose(file);
        printf("File '%s' sudah ada. Apakah Anda ingin menimpa? (y/n): ", filename);
        char response;
        scanf(" %c", &response);
        if (response != 'y') {
            printf("Proses penyimpanan dibatalkan.\n");
            return;
        }
    }

    file = fopen(path, "w");
    if (file == NULL) {
        printf("Error: Tidak dapat membuka file '%s' untuk menulis.\n", filename);
        return;
    }

    for (IdxType i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        fprintf(file, "%d\n", GetElmt(T, i)); // Tulis setiap elemen ke file
    }
  
    fclose(file);
    printf("Save file berhasil disimpan.\n");
}

int main() {
    printf("Program berhasil dijalankan.\n");
    return 0;
}
