#include "mesinkata.h"
#include "mesinkarakter.h"
#include <stdio.h>

boolean EndWord;
Word CurrentWord;

void IgnoreBlanks() {
    /* Mengabaikan satu atau beberapa BLANK */
    while (GetCC() == BLANK) {
        ADV();
    }
}

void STARTWORD() {
    /* Memulai mesin kata */
    START();
    IgnoreBlanks();
    if (IsEOP()) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD() {
    /* Maju ke kata berikutnya */
    IgnoreBlanks();
    if (IsEOP()) {
        EndWord = true;
    } else {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord() {
    /* Mengakuisisi kata dan menyimpannya dalam CurrentWord */
    int i = 0;
    while (GetCC() != BLANK && GetCC() != MARK && i < NMax) {
        CurrentWord.TabWord[i] = GetCC();
        i++;
        ADV();
    }
    CurrentWord.Length = i;
}
