#ifndef WORK_H
#define WORK_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "../mesinkata/mesinkata.h"
#include "../Kustom/Kustom.h"

#define MAX_LEN_WORK 100
#define WORD_LENGTH 5
#define MAX_ATTEMPTS 5

// Kamus Lokal
typedef struct {
    char name[MAX_LEN_WORK];
    int income;
    int duration;
} Job;

extern Job jobList[];       // List pekerjaan
extern int jobCount;        // Jumlah pekerjaan
extern Job selectedJob; 

void sleep(int second);/*
    Fungsi yang mengukur waktu untuk memberikan jeda.
*/

void WorkChallange(int *Money);

void tebakAngka(int *Money);

void getSecretWord(Word *secretWord);

void checkGuess(const char *secretWord, const char *guess, char *review);

void printState(char attempts[MAX_ATTEMPTS][WORD_LENGTH * 2 + 1], int attemptCount);

void WORDL3(int *Money);
#endif