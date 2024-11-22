#ifndef __item_h__
#define __item_h__

#include "boolean.h"
#include <stdlib.h>

#define MaxLen 100
#define MaxItem 100

typedef struct Item{
    char name[MaxLen]; // nama barang
    int price; // harga barang
} Item;

typedef struct ItemList{
    Item items[MaxItem]; // list barang yang ada
    int itemCount; // total jenis barang di store
} ItemList;

Item createItem(char *name, int price);
/* Membuat sebuah data barang baru dengan atribut nama dan harga yang diberikan */

void createItemList(ItemList *list);
/* Create list barang kosong */

void addItem(ItemList *list, Item *item);
/* Menambahkan barang baru ke list */

#endif