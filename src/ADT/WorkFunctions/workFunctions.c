#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "workFunctions.h"

// Kebutuhan Work
Job jobList[] = {
    {"Evil Lab Assistant", 100, 14},
    {"OWCA Hiring Manager", 4200, 21},
    {"Cikapundunginator Caretaker", 7000, 30},
    {"Mewing Specialist", 10000, 22},
    {"Inator Connoisseur", 997, 15}
};
int jobCount = 5;
Job selectedJob;

// Kebutuhan WorkChallange
int listAngka[] = {80,34,43,68,91,23,64,74,21,1,10};

// Fungsi
void sleep(int second) {
    time_t start_time = time(NULL); // Waktu mulai
    time_t end_time = start_time + second; // Waktu akhir

    while (time(NULL) < end_time) {
        // Loop sampai waktu sekarang melebihi waktu akhir
    }
}

void WorkChallange(int *Money) {
    // Kamus Lokal
    int pilihan;

    // Algoritma
    printf("Daftar challenge yang tersedia:\n");
    printf("1. Tebak Angka (biaya main=200)\n");
    printf("2. W0RDL399 (biaya main=500)\n\n");

    printf("Masukan challenge yang hendak dimainkan: ");
    scanf("%d", &pilihan);

    if (pilihan == 1)
    {
        tebakAngka(Money);  // Memanggil fungsi workChallenge dengan referensi user
    } else if (pilihan == 2)
    {
        WORDL3(Money);
    } else {
        printf("Pilihan tidak valid.\n");
    }
}

void tebakAngka(int *Money) {
    // Kamus Lokal
    srand(time(NULL));
    int hasilrandom = listAngka[rand() % (sizeof(listAngka) / sizeof(listAngka[0]))];
    int found = 0;
    int hadiah = 500;
    int jumlahTebakan = 0;
    
    //Algoritma
    while (found == 0 && jumlahTebakan != 10)
    {
        printf("Tebak angka: ");
        int tebakan = 0;
        scanf("%d", &tebakan);
        if (tebakan < hasilrandom)
        {
            printf("\nTebakanmu lebih kecil!\n");
            hadiah -= 50;
            jumlahTebakan += 1;
        } else if (tebakan > hasilrandom)
        {
            printf("\nTebakanmu lebih besar!\n");
            hadiah -= 50;
            jumlahTebakan += 1;
        } else {
            printf("\nTebakanmu benar! ");
            found = 1;
        }   
    }
    
    if (jumlahTebakan == 10)
    {
        printf("\nAnda gagal! Semoga beruntung di game selanjutnya!");
    } else {
        (*Money) += hadiah;
        printf("+%d rupiah telah ditambahkan ke akun anda.\n", hadiah);
    }

}

#define WORD_LENGTH 5
#define MAX_ATTEMPTS 5

void getSecretWord(Word *secretWord) {
    const char *words[] = {"TUBES", "ARRAY", "INDEX", "QUEUE", "STACK"};
    srand(time(0));
    StrcpyToWord(secretWord, words[rand() % 5]);
}

void checkGuess(const char *secretWord, const char *guess, char *review) {
    int isUsed[WORD_LENGTH] = {0};

    for (int i = 0; i < WORD_LENGTH; i++) {
        review[i * 2] = guess[i];
        review[i * 2 + 1] = '%';
    }
    review[WORD_LENGTH * 2] = '\0';

    for (int i = 0; i < WORD_LENGTH; i++) {
        if (guess[i] == secretWord[i]) {
            review[i * 2 + 1] = ' ';
            isUsed[i] = 1;
        }
    }
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (review[i * 2 + 1] == '%') {
            for (int j = 0; j < WORD_LENGTH; j++) {
                if (!isUsed[j] && guess[i] == secretWord[j]) {
                    review[i * 2 + 1] = '*';
                    isUsed[j] = 1;
                    break;
                }
            }
        }
    }
}

void printState(char attempts[MAX_ATTEMPTS][WORD_LENGTH * 2 + 1], int attemptCount) {
    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        if (i < attemptCount)
            printf("%s\n", attempts[i]);
        else
            printf("_ _ _ _ _\n");
    }
}

void WORDL3(int *Money) {
    Word secretWord;;
    char attempts[MAX_ATTEMPTS][WORD_LENGTH * 2 + 1] = {{0}};
    int attemptCount = 0;
    
    getSecretWord(&secretWord);
    printf("WELCOME TO W0RDL3, YOU HAVE 5 CHANCES TO ANSWER BEFORE YOU LOSE!\n\n");
    printState(attempts, attemptCount);

    while (attemptCount < MAX_ATTEMPTS) {
        printf("\nMasukan kata tebakan Anda: ");
        START();  

        char guess[WORD_LENGTH + 1] = {0};
        int index = 0;

        while (!EOP && index < WORD_LENGTH) {
            guess[index++] = GetCC(); 
            ADV(); 
        }

        if (index != WORD_LENGTH) {
            printf("Invalid input. Please enter a %d-letter word.\n", WORD_LENGTH);
            continue;
        }

        guess[WORD_LENGTH] = '\0'; 

        checkGuess(secretWord.TabWord, guess, attempts[attemptCount]);
        printf("\nHasil:\n");
        printState(attempts, attemptCount + 1);

        if (IsSame(guess, secretWord.TabWord)) { 
            (*Money) += 1500;
            printf("\nSelamat, Anda menang!\n+1500 rupiah telah ditambahkan ke akun Anda.\n");
            return;
        }

        attemptCount++;
    }

    printf("\nBoo! Anda kalah. The correct word was: %s\n", secretWord.TabWord);
}