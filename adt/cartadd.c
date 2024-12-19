#include "cartadd.h"

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