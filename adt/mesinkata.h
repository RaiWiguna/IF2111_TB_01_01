/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkar.h"
#include <stdio.h>

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

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void IgnoreBlanks_File();

void STARTWORD();

void STARTWORD_Item(FILE *file);
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

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

void StrcpyToWord(Word *dest, const char *src);/*
   Mengcopy sebuah string kedalam bentuk array
*/

void StrcpyToString(string dest, const Word *src);/*
   Mencopy sebuah word (menyimpan length, dan tabword), menjadi sebuah string saja (menyimpan nilai tabword)
   * Berfungsi mencegah pointersharing
*/
boolean IsSame(const char *str1,const char *str2);/*
   Melakukan komparasi apakah kedua kata sama atau tidak
*/
#endif