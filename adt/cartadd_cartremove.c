#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "map.h"
#include "string.h"

// Inisialisasi toko dan keranjang
Map toko;
LinkedList keranjang;

void initSystem() {
    // Inisialisasi toko dan keranjang
    CreateEmptyMap(&toko);
    CreateList(&keranjang);

    // Tambahkan barang ke toko sebagai contoh
    InsertMap(&toko, "AK47", 50);
    InsertMap(&toko, "Granat", 30);
    InsertMap(&toko, "Peluru", 100);
}

void cartAdd(char *namaBarang, int kuantitas) {
    // Periksa apakah barang ada di toko
    int idx = SearchMap(toko, namaBarang);
    if (idx == Undefined) {
        printf("Barang tidak ada di toko!\n");
        return;
    }

    // Periksa stok barang di toko
    if (toko.Elements[idx].Value < kuantitas) {
        printf("Stok barang tidak mencukupi!\n");
        return;
    }

    // Tambahkan barang ke keranjang
    Address node = SearchList(keranjang, namaBarang);
    if (node != NIL) {
        // Jika barang sudah ada di keranjang, tambahkan kuantitas
        node->info.quantity += kuantitas;
    } else {
        // Jika barang belum ada, tambahkan node baru
        Item newItem;
        strcpy_custom(newItem.name, namaBarang);
        newItem.quantity = kuantitas;
        InsertLast(&keranjang, newItem);
    }

    // Kurangi stok di toko
    toko.Elements[idx].Value -= kuantitas;
    printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", kuantitas, namaBarang);
}

void cartRemove(char *namaBarang, int kuantitas) {
    // Periksa apakah barang ada di keranjang
    Address node = SearchList(keranjang, namaBarang);
    if (node == NIL) {
        printf("Barang tidak ada di keranjang!\n");
        return;
    }

    // Periksa kuantitas barang di keranjang
    if (node->info.quantity < kuantitas) {
        printf("Kuantitas barang di keranjang tidak mencukupi!\n");
        return;
    }

    // Kurangi kuantitas barang di keranjang
    node->info.quantity -= kuantitas;
    if (node->info.quantity == 0) {
        // Hapus node jika kuantitas menjadi nol
        DeleteNode(&keranjang, node);
    }

    // Tambahkan kembali stok ke toko
    int idx = SearchMap(toko, namaBarang);
    toko.Elements[idx].Value += kuantitas;
    printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", kuantitas, namaBarang);
}

void displayCart() {
    // Tampilkan isi keranjang
    if (IsListEmpty(keranjang)) {
        printf("Keranjang belanja kosong!\n");
        return;
    }

    printf("Isi keranjang belanja:\n");
    Address p = First(keranjang);
    while (p != NIL) {
        printf("- %s: %d\n", p->info.name, p->info.quantity);
        p = Next(p);
    }
}

/*  INI KALO MAU DICOBA 
int main() {                     
    initSystem();
    char command[100];

    printf("Selamat datang di PURRMART!\n");
    while (1) {
        printf(">> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strncmp(command, "CART ADD", 8) == 0) {
            char namaBarang[50];
            int kuantitas;
            sscanf(command + 9, "%s %d", namaBarang, &kuantitas);
            cartAdd(namaBarang, kuantitas);
        } else if (strncmp(command, "CART REMOVE", 11) == 0) {
            char namaBarang[50];
            int kuantitas;
            sscanf(command + 12, "%s %d", namaBarang, &kuantitas);
            cartRemove(namaBarang, kuantitas);
        } else if (strcmp(command, "DISPLAY CART") == 0) {
            displayCart();
        } else if (strcmp(command, "QUIT") == 0) {
            break;
        } else {
            printf("Perintah tidak dikenal!\n");
        }
    }

    return 0;
} */
