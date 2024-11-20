#ifndef MESINKATA_H
#define MESINKATA_H

#include "mesinkarakter.h"

#define NMax 100
#define BLANK ' '

typedef struct {
    char TabKata[NMax];
    int Length;
} Kata;

extern Kata CKata;

void STARTKATA();
void ADVKATA();
void SalinKata();
void IgnoreBlank();

#endif