#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mesinkarakter.c"
#include "boolean.h"

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

void playGame() {
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

int main() {
    playGame();
    return 0;
}
