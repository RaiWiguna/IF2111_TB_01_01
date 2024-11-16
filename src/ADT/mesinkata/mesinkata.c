#include <stdio.h>
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