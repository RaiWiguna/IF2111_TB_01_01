/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "..\..\boolean.h"
#include "..\mesinkar\mesinkar.h"

#define NMax 50
#define BLANK ' '

typedef char* string;
typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word CurrentWord;
extern Word CurrentWord1;
extern Word CurrentWord2;
extern Word CurrentWord3;
extern Word CurrentWord4;
extern Word CurrentWord5;


void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void IgnoreBlanks_File();

void STARTWORD();

void STARTWORD_Item(FILE *file);

void STARTWORD_User(FILE *file);/*
   Membaca user
*/
void ADVWORD();

void ADVWORD_Item();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();

void CopyWord_Item();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyWord_User();/*
   Khusus mengcopy user dari file.txt
*/
void StrcpyToWord(Word *dest, const char *src);/*
   Mengcopy sebuah string kedalam bentuk array
*/

void StrcpyToString(string dest, const Word *src);/*
   Mencopy sebuah word (menyimpan length, dan tabword), menjadi sebuah string saja (menyimpan nilai tabword)
   * Berfungsi mencegah pointersharing
*/
void copyString(char *dest, const char *src); /*
   Melakukan copy string untuk list statis
*/

// Processing
int strLength(const char *str); /*
   Menghitung panjang dari sebuah kata
*/

// Boolean
boolean IsSame(const char *str1,const char *str2);/*
   Melakukan komparasi apakah kedua kata sama atau tidak
*/
#endif