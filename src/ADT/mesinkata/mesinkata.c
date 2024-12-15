#include <stdio.h>

#include "../../boolean.h"
#include "mesinkata.h"

boolean EndWord;
Word CurrentWord;
Word CurrentWord1;
Word CurrentWord2;
Word CurrentWord3;
Word CurrentWord4;
Word CurrentWord5;
Word CurrentWordWithBlank;
Word CurrentWordStringToInteger;


void IgnoreBlanks() {
    while (currentChar == BLANK && currentChar != MARK) {
        ADV();
    }
}

void IgnoreBlanks_File() {
    while (currentChar == BLANK && currentChar != MARK) {
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
    if (currentChar == MARK) {
        EndWord = true;  
    } else {
        EndWord = false;
        CopyWord_Item(); 
    }
}

void STARTWORD_User(FILE *file){
    START_File(file); 
    IgnoreBlanks();  
    if (currentChar == MARK) {
        EndWord = true;  
    } else {
        EndWord = false;
        CopyWord_User(); 
    }
}

void STARTWORD_Looping(FILE *file){
    START_File(file);
    CurrentWordStringToInteger.Length =1;
    CurrentWordStringToInteger.TabWord[0]=currentChar;
    IgnoreBlanks();
    if(currentChar == MARK){
        EndWord = true;
    }
    else{
        Skip_Line(file);
    }
}

void STARTWORD_WithBlank(FILE *file){
    START_File(file); 
    IgnoreBlanks();  
    if (currentChar == MARK) {
        EndWord = true;  
    } else {
        EndWord = false;
        CopyWord_WithBlank(); 
    }
}
void Skip_Line(FILE *file){
    while(currentChar != NEWLINE){
        ADV_File();
    }
}

void Skip_Looping(FILE *file, int n){
    for(int i=0;i<n;i++){
        STARTWORD_Looping(file);
    }
    if(n==0){
       Skip_Line(file); // Tetap melakukan pembacaan pada baris yang mengandung nilai 0
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

void ADVWORD_Item() {
    IgnoreBlanks();  
    if (currentChar == MARK) {
        EndWord = true;  
    } else {
        CopyWord_Item();  
    }
}

void CopyWord() {
    CurrentWord.Length = 0;
    while (currentChar != MARK && CurrentWord.Length < NMax) { 
        CurrentWord.TabWord[CurrentWord.Length] = currentChar; 
        CurrentWord.Length++; 
        ADV(); 
    }
    CurrentWord.TabWord[CurrentWord.Length] = '\0'; 
}

void CopyWord_WithBlank(){
    // Kamus Lokal
    CurrentWordWithBlank.Length=0;

    //Algoritma
    while(currentChar != MARK && CurrentWordWithBlank.Length < NMax && currentChar!=NEWLINE) {
        CurrentWordWithBlank.TabWord[CurrentWordWithBlank.Length] = currentChar; 
        CurrentWordWithBlank.Length++; 
        ADV_File(); 
    }
    CurrentWordWithBlank.TabWord[CurrentWordWithBlank.Length]='\0';

}

void CopyWord_Item() {
    // Kamus Lokal
    CurrentWord1.Length=0;
    CurrentWord2.Length=0;

    // Algoritma
    while(currentChar!=BLANK && currentChar != MARK && CurrentWord1.Length < NMax && currentChar!=NEWLINE) {
        CurrentWord1.TabWord[CurrentWord1.Length] = currentChar; 
        CurrentWord1.Length++; 
        ADV_File(); 
    }
    
    CurrentWord1.TabWord[CurrentWord1.Length] = '\0';
    IgnoreBlanks_File();

    while(currentChar != MARK && CurrentWord2.Length < NMax && currentChar!=NEWLINE) {
        CurrentWord2.TabWord[CurrentWord2.Length] = currentChar; 
        CurrentWord2.Length++; 
        ADV_File(); 
    }
    
    CurrentWord2.TabWord[CurrentWord2.Length] = '\0';
}

void CopyWord_User(){
    // Kamus Lokal 
    CurrentWord3.Length=0;
    CurrentWord4.Length=0;
    CurrentWord5.Length=0;

    // Algoritma
    while(currentChar!=BLANK && currentChar != MARK && CurrentWord3.Length < NMax && currentChar!=NEWLINE) {
        CurrentWord3.TabWord[CurrentWord3.Length] = currentChar; 
        CurrentWord3.Length++; 
        ADV_File(); 
    }
    CurrentWord3.TabWord[CurrentWord3.Length] = '\0';
    IgnoreBlanks_File();

    while(currentChar!=BLANK && currentChar != MARK && CurrentWord4.Length < NMax && currentChar!=NEWLINE) {
        CurrentWord4.TabWord[CurrentWord4.Length] = currentChar; 
        CurrentWord4.Length++; 
        ADV_File(); 
    }
    CurrentWord4.TabWord[CurrentWord4.Length] = '\0';
    IgnoreBlanks_File();

    while(currentChar!=BLANK && currentChar != MARK && CurrentWord5.Length < NMax && currentChar!=NEWLINE) {
        CurrentWord5.TabWord[CurrentWord5.Length] = currentChar; 
        CurrentWord5.Length++; 
        ADV_File(); 
    }
    CurrentWord5.TabWord[CurrentWord5.Length] = '\0';
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
        printf("%d",i);
        dest[i] = src->TabWord[i];
        i++;
    }
    dest[i] = '\0'; // Akhiri dengan null terminator
}

void copyString(char *dest, const char *src) {
    while ((*dest++ = *src++));
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