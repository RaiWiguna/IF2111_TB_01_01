#include <stdio.h>
#include "mesinkar.h"

char currentChar;
boolean EOP;
static FILE *pita;
static int retval;

void START(){
    pita =stdin;
    ADV();
}
void START_File(FILE *file) {
    /* Mesin siap dioperasikan. Pita disiapkan ... */
    /* Algoritma */
    pita = file;
    ADV_File();
}

void ADV(){
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == EOF||currentChar=='\n');
    if (EOP) {
        currentChar ='\0';
    }
}

void ADV_File() {
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