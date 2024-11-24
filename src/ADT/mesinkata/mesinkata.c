#include <stdio.h>

#include "../../boolean.h"
#include "mesinkata.h"

boolean EndWord;
Word CurrentWord1;
Word CurrentWord2;


void IgnoreBlanks() {
    while (currentChar == BLANK && currentChar != MARK) {
        ADV();
    }
}

void STARTWORD_Item(FILE *file) {
    START(file); 
    IgnoreBlanks();  
    if (currentChar == MARK) {
        EndWord = true;  
    } else {
        EndWord = false;
        CopyWord_Item(); 
    }
}

void ADVWORD_Item() {
    IgnoreBlanks();  
    if (currentChar == MARK) {
        EndWord = true;  
    } else {
        CopyWord_Item();  
    }
}

void CopyWord_Item() {
    // Kamus Lokal
    CurrentWord1.Length=0;
    CurrentWord2.Length=0;

    // Algoritma
    while(currentChar!=BLANK && currentChar != MARK && CurrentWord1.Length < NMax && currentChar!=NEWLINE) {
        CurrentWord1.TabWord[CurrentWord1.Length] = currentChar; 
        CurrentWord1.Length++; 
        ADV(); 
    }
    
    CurrentWord1.TabWord[CurrentWord1.Length] = '\0';
    IgnoreBlanks();
    while(currentChar != MARK && CurrentWord2.Length < NMax && currentChar!=NEWLINE) {
        CurrentWord2.TabWord[CurrentWord2.Length] = currentChar; 
        CurrentWord2.Length++; 
        ADV(); 
    }
    
    CurrentWord2.TabWord[CurrentWord2.Length] = '\0';
}

void StrcpyToWord(Word *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0' && i < NMax) {
        (*dest).TabWord[i] = src[i];
        i++;
    }

    if (i < NMax) {
        (*dest).TabWord[i] = '\0';
    } else {
        (*dest).TabWord[NMax - 1] = '\0';
    }
    
    (*dest).Length = i;
}

boolean IsSame(const char *str1,const char *str2){
    // Kamus Lokal 
    int i =0;
    // Algoritma
    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i] != str2[i]){
            return false;
        }
        i++;
    }
    return true;
}