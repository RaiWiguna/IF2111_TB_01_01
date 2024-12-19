#include "cartremove.h"

Map toko;
LinkedList keranjang;

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