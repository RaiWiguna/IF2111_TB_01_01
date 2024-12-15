/* MODUL SCAN FILE*/
/* Berisi definisi dan semua primitif untuk membaca file.txt*/

#ifndef ScanFile
#define ScanFile

#include <stdio.h>

#include "../../boolean.h"
#include "../ArrayDinamis/ArrayDinamis.h"
#include "../Queue/queue.h"
#include "../ListStatis/liststatis.h"
#include "../ListLinier/listlinier.h"

/* Kamus Umum */

// Process
void ReadFile(FILE *file,ArrayDin *item, ArrayDin *UserItem,List *Account);/*
Hanya untuk membuka dan membaca file
*/
void ReadItem(FILE *file,ArrayDin *Item);/*
Membaca bagian item pada file
*/
void ReadUser(FILE *file,List *Account, ArrayDin *UserItem);/*
Membaca bagian item pada user;
*/

void WriteFile(FILE *file);/*
Menulis ulang file setelah dilakukan save
*/

void CreateUserWhislist(FILE *file, ListLinier *Whistlist, Word LoginAccount);/*
Membuat whislist dari akun yang telah login
*/

void CreateUserItem(FILE *file, ArrayDin *UserItem, Word LoginAccount);/*
Membuat array yang berisikan Item dari Akun yang telah login
*/

#endif