#ifndef CART_H
#define CART_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "map.h"
#include "string.h"

// Struktur untuk menyimpan riwayat pembelian
typedef struct {
    char name[50];
    int totalPrice;
} History;

// Variabel global
extern History purchaseHistory;
extern int userBalance; // Saldo pengguna

// Toko dan keranjang belanja
extern Map toko;
extern LinkedList keranjang;

// Struktur tambahan untuk kuantitas barang
extern Map cartQuantity;

// Deklarasi fungsi
void cartAdd(char *namaBarang, int kuantitas);
void cartRemove(char *namaBarang, int kuantitas);
void cartShow();
void cartPay();

#endif
