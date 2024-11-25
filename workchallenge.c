#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "workchallenge.h"
#include "mesinkata.h"

int listAngka[] = {80, 11, 63, 51, 83, 15, 31, 7, 94, 73, 8, 42, 12, 53, 43, 53, 53, 21, 44, 6};

int main() {
    User user;  // Membuat objek User
    user.money = 1000;  // Menetapkan saldo awal

    printf("Daftar challenge yang tersedia:\n");
    printf("1. Tebak Angka (biaya main=200)\n");
    printf("2. W0RDL399 (biaya main=500)\n\n");

    printf("Masukan challenge yang hendak dimainkan: ");
    int pilihan;
    scanf("%d", &pilihan);

    if (pilihan == 1)
    {
        tebakAngka(&user);  // Memanggil fungsi workChallenge dengan referensi user
    } else if (pilihan == 2)
    {
        WORDL3();
    } else {
        printf("Pilihan tidak valid.\n");
    }

    return 0;
}

void tebakAngka(User *u) {

    srand(time(NULL));
    int hasilrandom = listAngka[rand() % (sizeof(listAngka) / sizeof(listAngka[0]))];
    
    int found = 0;
    int hadiah = 500;
    int jumlahTebakan = 0;
    printf("\n");
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
        u->money += hadiah;
        printf("+%d rupiah telah ditambahkan ke akun anda.\n", hadiah);
    }

}

#define WORD_LENGTH 5
#define MAX_ATTEMPTS 5

void copyString(char *dest, const char *src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0'; 
}

int compareString(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

void getSecretWord(char *secretWord) {
    const char *words[] = {"TUBES", "ARRAY", "INDEX", "QUEUE", "STACK"};
    srand(time(0));
    copyString(secretWord, words[rand() % 5]);
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

void WORDL3() {
    char secretWord[WORD_LENGTH + 1];
    char attempts[MAX_ATTEMPTS][WORD_LENGTH * 2 + 1] = {{0}};
    int attemptCount = 0;
    
    getSecretWord(secretWord);
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

        checkGuess(secretWord, guess, attempts[attemptCount]);
        printf("\nHasil:\n");
        printState(attempts, attemptCount + 1);

        if (compareString(guess, secretWord) == 0) { 
            printf("\nSelamat, Anda menang!\n+1500 rupiah telah ditambahkan ke akun Anda.\n");
            return;
        }

        attemptCount++;
    }

    printf("\nBoo! Anda kalah. The correct word was: %s\n", secretWord);
}