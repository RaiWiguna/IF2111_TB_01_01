#include <stdio.h>

#include "../../boolean.h"
#include "mesinkata.h"

boolean EndWord;
Word CurrentWord;

void IgnoreBlanks() {
    while (currentChar == BLANK && currentChar != MARK) {
        ADV();
    }
}

void STARTWORD() {
    START(); 
    IgnoreBlanks();  
    if (currentChar == MARK) {
        EndWord = true;  
    } else {
        EndWord = false;
        CopyWord(); 
    }
}

void ADVWORD() {
    IgnoreBlanks();  
    if (currentChar == MARK) {
        EndWord = true;  
    } else {
        CopyWord();  
    }
}

void CopyWord() {
    CurrentWord.Length = 0; 
    while (currentChar != BLANK && currentChar != MARK && CurrentWord.Length < NMax) {
        CurrentWord.TabWord[CurrentWord.Length] = currentChar; 
        CurrentWord.Length++; 
        ADV(); 
    }
    
    CurrentWord.TabWord[CurrentWord.Length] = '\0';
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