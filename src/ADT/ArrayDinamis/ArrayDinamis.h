/* MODUL ARRAY DINAMIS */
/* Berisi definisi dan semua primitif pemrosesan array dinamis */

#ifndef ArrDin
#define ArrDin

#include <stdio.h>
#include "../../boolean.h"
#include "../mesinkata/mesinkata.h"

/* Kamus Umum */
#define MAX_LEN 100
#define InitialSize 10

// Variable 
typedef int Index;

typedef struct {
  char name[MAX_LEN];
  int price;
} Item;

typedef struct {
    Item* elements;  // Array elemen bertipe Item
    int Capacity;    // Kapasitas maksimum
    int Neff;        // Banyaknya elemen efektif
} ArrayDin;

// Konstruktor 
void MakeArrayDin(ArrayDin *array);/*
    Membuat array dinamis yang kosong
*/

// Processing 
int GetCapacity(ArrayDin array);/*
Mengembalikan kapasitas dari array
*/

int LengthArrDin(ArrayDin array);/*
Mengembalikan nilai ekeftif dari array
*/

void CetakNameArrayDin(ArrayDin array);/*
Mencetak isi nama dari array
*/

void CetakArrayDin(ArrayDin array);/*
Mencetak isi dari array
*/

void UpdateCapacity(ArrayDin *array);/*
    Mengupdate kapasitas yang disediakan.
*/ 

void DeallocateArrDin(ArrayDin *array);/*
Membebaskan memori yang digunakan
*/

void MoveRightArrDin(ArrayDin *array,Index from);/*
Memindahkan isi array kekanan dimulai dari index from
*/

void MoveLeftArrDin(ArrayDin *array,Index from);/*
Memindahkan isi array kekiri dimulai dari index from
*/

string GetInput(ArrayDin array, Index i);/*
    Mengambil input dari sebuah indeks 
*/

// Pengolahan Data
void InsertFirstNameArrDin(ArrayDin *array, string input);/*
    Memasukkan pada element pertama, kedalam array dinamis.
*/

void InsertFirstArrDin(ArrayDin *array,string price,string name);/*
    Memasukkan  name ke element pertama, kedalam array dinamis.
*/

void InsertAtNameArrDin(ArrayDin *array, string input, Index i);/*
    Memasukkan input kedalam Array sesuai indeks, dengan batasan indeks < nilai efektif.
*/

void InsertAtArrDin(ArrayDin *array, string price, string name, Index i);/*
    Memasukkan name kedalam Array sesuai indeks, dengan batasan indeks < nilai efektif.
*/


void InsertLastNameArrDin(ArrayDin *array, string input);/*
    Memasukkan name pada akhir array
*/

void InsertLastArrDin(ArrayDin *array,string price,string name);/*
    Memasukkan elemen pada akhir array
*/

void DeleteFirstArrDin(ArrayDin *array);/*
Menghapus element pertama
*/

void DeleteAtArrDin(ArrayDin *array, Index i);/*
Menghapus element sesuai indeks
*/

void DeleteLastArrDin(ArrayDin *array);/*
Menghapus element terakhir
*/

// Searching Metode 
Index SearchArrDin(ArrayDin array, string input);/*
    Membalikkan nilai indeks dari elemen yang dicari, mengambilkkan -1 jika tidak ditemukan
*/

// Boolean
boolean IsEmpty(ArrayDin array);

boolean IsInArrDin(ArrayDin array,string input);/*
    Membalikan nilai, apakah elemen yang dicari ada di array atau tidak.
*/

#endif