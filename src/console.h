#ifndef console.h
#define console.h

#include <stdio.h>
#include "src/ADT/mesinkata/mesinkata.h"
#include "src/ADT/ArrayDinamis/ArrayDinamis.h"
#include "src/ADT/ScanFile/scanfile.h"
#include "src/ADT/Queue/queue.h"

void Load(ArrayDin *Item,boolean *login);/*
    Melakukan Load File
*/

void Start(boolean login);/*
    Mengirimkan sebuah text apabila berhasil melakukan load.    
*/

void storeList(ArrayDin Item);/*
    Menampilkan list store
*/

void storeRequest(Queue *Req, ArrayDin Item); /*
    Melakukan store request;
*/

void storeSupply(Queue Req, ArrayDin *Item); /*
    Menambahkan Suplly, memasukkan kedalam array Store
*/
void storeRemove(ArrayDin *Item);/*
    Melakukan remove item pada store, hanya di remove pada array akan tersimpan apa bila melakukan save.
*/

#endif