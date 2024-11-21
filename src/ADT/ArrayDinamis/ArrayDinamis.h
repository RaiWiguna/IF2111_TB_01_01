/* MODUL ARRAY DINAMIS */
/* Berisi definisi dan semua primitif pemrosesan array dinamis */

#ifndef ArrDin
#define ArrDin

#include <stdio.h>
#include "../../boolean.h"

/* Kamus Umum */
#define InitialSize 10

// Variable 
typedef char* string;
typedef int Index;
typedef struct 
{
    string* input;
    int Capacity;
    int Neff;
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
void InsertFirstArrDin(ArrayDin *array, string input);/*
    Memasukkan pada element pertama, kedalam array dinamis.
*/

void InsertAtArrDin(ArrayDin *array, string input, Index i);/*
    Memasukkan input kedalam Array sesuai indeks, dengan batasan indeks < nilai efektif.
*/

void InsertLastArrDin(ArrayDin *array, string input);/*
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

#endif