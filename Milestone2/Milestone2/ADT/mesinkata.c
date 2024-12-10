#include <stdio.h>

#include "mesinkata.h"

boolean EndWord;
Word CurrentWord;
Word CurrentWord1;
Word CurrentWord2;


void IgnoreBlanks() {
    while (currentChar == BLANK && currentChar != MARKO) {
        ADV();
    }
}

void IgnoreBlanks_File() {
    while (currentChar == BLANK && currentChar != MARKO) {
        ADV_File();
    }
}

void STARTWORD() {
    for(int i=0; i< NMax ;i++){
        CurrentWord.TabWord[i] ='\0';
    }
    START(); 
    IgnoreBlanks();  
    if (currentChar == '\0') {
        EndWord = true;  
    } else {
        EndWord = false;
        CopyWord(); 
    }
}

void STARTWORD_Item(FILE *file) {
    START_File(file); 
    IgnoreBlanks();  
    if (currentChar == MARKO) {
        EndWord = true;  
    } else {
        EndWord = false;
        CopyWord_Item(); 
    }
}

void ADVWORD() {
    IgnoreBlanks();  
    if (currentChar == MARKO) {
        EndWord = true;  
    } else {
        CopyWord();  
    }
}

void ADVWORD_Item() {
    IgnoreBlanks();  
    if (currentChar == MARKO) {
        EndWord = true;  
    } else {
        CopyWord_Item();  
    }
}

void CopyWord() {
    CurrentWord.Length = 0;
    while (currentChar != MARKO && CurrentWord.Length < NMax) { 
        CurrentWord.TabWord[CurrentWord.Length] = currentChar; 
        CurrentWord.Length++; 
        ADV(); 
    }
    CurrentWord.TabWord[CurrentWord.Length] = '\0'; 
}

void CopyWord_Item() {
    // Kamus Lokal
    CurrentWord1.Length=0;
    CurrentWord2.Length=0;

    // Algoritma
    while(currentChar!=BLANK && currentChar != MARKO && CurrentWord1.Length < NMax && currentChar!=NEWLINE) {
        CurrentWord1.TabWord[CurrentWord1.Length] = currentChar; 
        CurrentWord1.Length++; 
        ADV_File(); 
    }
    
    CurrentWord1.TabWord[CurrentWord1.Length] = '\0';
    IgnoreBlanks_File();
    while(currentChar != MARKO && CurrentWord2.Length < NMax && currentChar!=NEWLINE) {
        CurrentWord2.TabWord[CurrentWord2.Length] = currentChar; 
        CurrentWord2.Length++; 
        ADV_File(); 
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

void StrcpyToString(string dest, const Word *src) {
    int i = 0;
    while (i < src->Length && i < NMax - 1) { // Pastikan tidak melebihi batas
        dest[i] = src->TabWord[i];
        i++;
    }
    dest[i] = '\0'; // Akhiri dengan null terminator
}

// Processing
int strLength(const char *str){
    // Kamus Lokal
    int i =0, strLen=0;
    // Algoritma
    while(str[i] != '\0'){
        i++;
        strLen++;
    }
    return strLen;
}
// boolean
boolean IsSame(const char *str1,const char *str2){
    // Kamus Lokal 
    int i =0;
    // Algoritma
    if(strLength(str1)!= strLength(str2)){
        return false;
    }
    else{
        while(str1[i] != '\0' && str2[i] != '\0'){
            if(str1[i] != str2[i]){
                return false;
            }
        i++;
        }
    }
    return true;
}