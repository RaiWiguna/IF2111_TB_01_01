#include "cart.h"
#include <stdio.h>
#include <stdlib.h>

// Global variables
Map toko;          
LinkedList keranjang;
Map cartQuantity;    
History purchaseHistory;
int userBalance = 1000;

void cartAdd(char *namaBarang, int kuantitas) {
    int idx = idxMap(toko, namaBarang);
    if (idx == Undefined) {
        printf("Barang tidak ada di toko!\n");
        return;
    }

    if (toko.Elements[idx].Value < kuantitas) {
        printf("Stok barang tidak mencukupi!\n");
        return;
    }

    Address node = Search(keranjang, namaBarang);
    if (node == NIL) {
        Address newNode = Allocate(strdup_custom(namaBarang));
        InsertLastL(&keranjang, newNode);
        InsertMap(&cartQuantity, namaBarang, kuantitas);
    } else {
        int currentQuantity = cartQuantity.Elements[idxMap(cartQuantity, namaBarang)].Value;
        cartQuantity.Elements[idxMap(cartQuantity, namaBarang)].Value = currentQuantity + kuantitas;
    }

    toko.Elements[idx].Value -= kuantitas;
    printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", kuantitas, namaBarang);
}

void cartRemove(char *namaBarang, int kuantitas) {
    int idxCart = idxMap(cartQuantity, namaBarang);
    if (idxCart == Undefined) {
        printf("Barang tidak ada di keranjang!\n");
        return;
    }

    int currentQuantity = cartQuantity.Elements[idxCart].Value;
    if (currentQuantity < kuantitas) {
        printf("Kuantitas barang di keranjang tidak mencukupi!\n");
        return;
    }

    cartQuantity.Elements[idxCart].Value -= kuantitas;

    if (cartQuantity.Elements[idxCart].Value == 0) {
        DeleteNode(&keranjang, namaBarang);
        DeleteMap(&cartQuantity, namaBarang);
    }

    int idxToko = idxMap(toko, namaBarang);
    toko.Elements[idxToko].Value += kuantitas;

    printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", kuantitas, namaBarang);
}

void cartShow() {
    if (IsListEmpty(keranjang)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    printf("Berikut adalah isi keranjangmu:\n");
    printf("Kuantitas\tNama\tTotal\n");

    Address p = FirstL(keranjang);
    int totalHarga = 0;

    while (p != NIL) {
        char *namaBarang = InfoL(p);
        int quantity = cartQuantity.Elements[idxMap(cartQuantity, namaBarang)].Value;
        int hargaSatuan = toko.Elements[idxMap(toko, namaBarang)].Value;
        int subtotal = quantity * hargaSatuan;

        printf("%d\t\t%s\t%d\n", quantity, namaBarang, subtotal);
        totalHarga += subtotal;

        p = NextL(p);
    }

    printf("Total biaya yang harus dikeluarkan adalah %d.\n", totalHarga);
}

void cartPay() {
    if (IsListEmpty(keranjang)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    printf("Kamu akan membeli barang-barang berikut:\n");
    printf("Kuantitas\tNama\tTotal\n");

    Address p = FirstL(keranjang);
    int totalBiaya = 0;
    int maxSubtotal = 0;
    char bestItem[50];
    bestItem[0] = '\0';  // Initialize empty string

    while (p != NIL) {
        char *namaBarang = InfoL(p);
        int quantity = cartQuantity.Elements[idxMap(cartQuantity, namaBarang)].Value;
        int hargaSatuan = toko.Elements[idxMap(toko, namaBarang)].Value;
        int subtotal = quantity * hargaSatuan;

        printf("%d\t\t%s\t%d\n", quantity, namaBarang, subtotal);
        totalBiaya += subtotal;

        if (subtotal > maxSubtotal || (subtotal == maxSubtotal && strcmp_custom(namaBarang, bestItem) > 0)) {
            maxSubtotal = subtotal;
            strcpy_custom(bestItem, namaBarang);
        }

        p = NextL(p);
    }

    printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak): ", totalBiaya);
    
    START();
    Word answer;
    CopyWord();
    
    if (isKataEqual(CurrentWord.TabWord, "Ya")) {
        if (userBalance >= totalBiaya) {
            userBalance -= totalBiaya;

            strcpy_custom(purchaseHistory.name, bestItem);
            purchaseHistory.totalPrice = maxSubtotal;

            while (!IsListEmpty(keranjang)) {
                Address toDelete;
                DeleteFirstL(&keranjang, &toDelete);
                Deallocate(toDelete);
            }
            CreateEmptyMap(&cartQuantity);

            printf("Selamat kamu telah membeli barang-barang tersebut!\n");
        } else {
            printf("Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", userBalance);
        }
    } else if (isKataEqual(CurrentWord.TabWord, "Tidak")) {
        printf("Pembelian dibatalkan.\n");
    } else {
        printf("Input tidak valid. Kembali ke menu utama.\n");
    }
}