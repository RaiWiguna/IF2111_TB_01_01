/* MODUL SCAN FILE*/
/* Berisi definisi dan semua primitif untuk membaca file.txt*/

#ifndef ScanFile
#define ScanFile

#include <stdio.h>

#include "../../boolean.h"
#include "../ArrayDinamis/ArrayDinamis.h"

/* Kamus Umum */

// Process
void ReadFile(const char *filePath,ArrayDin *item);/*
Hanya untuk membuka dan membaca file
*/
void ReadItem(FILE *file,ArrayDin *Item);/*
Membaca bagian item pada file
*/
void ReadUser(FILE *file);/*
Membaca bagian item pada user;
*/

void WriteFile(FILE *file);/*
Menulis ulang file setelah dilakukan save
*/

#endif