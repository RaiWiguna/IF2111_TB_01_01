#include <stdio.h>
#include "mesinkar.h"

char currentChar;
boolean EOP;
static FILE *pita;
static int retval;

void START(FILE *file) {
    /* Mesin siap dioperasikan. Pita disiapkan ... */
    /* Algoritma */
    pita = file;
    ADV();
}

void ADV() {
    /* Pita dimajukan satu karakter. ... */
    /* Algoritma */ 
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
    if (EOP) {
        fclose(pita);
    }
}

char GetCC() {
    /* Mengirimkan currentChar */
    /* Algoritma */
    return currentChar;
}

boolean IsEOP() {
    /* Mengirimkan true jika currentChar = MARK */
    /* Algoritma */
    return EOP;
}