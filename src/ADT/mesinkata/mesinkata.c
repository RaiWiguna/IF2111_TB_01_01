#include "mesinkata.h"
#include <stdio.h>

Kata CKata;

void IgnoreBlank() {
    while (CC == BLANK) {
        ADV();
    }
}

void STARTKATA() {
    START();
    IgnoreBlank();
    if (CC != MARK) {
        SalinKata();
    }
}

void ADVKATA() {
    IgnoreBlank();
    if (CC != MARK) {
        SalinKata();
    }
}

void SalinKata() {
    int i = 0;
    while ((CC != MARK) && (CC != BLANK) && (i < NMax)) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.TabKata[i] = '\0';
    CKata.Length = i;
}
