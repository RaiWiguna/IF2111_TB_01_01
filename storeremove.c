#include "storeremove.h"
#include "string.h"

void storeRemove(arraydin *Arr) {
    char Item[100];
    scanf("Nama barang yang akan dihapus: %s", Item);

    for (int i = 0; i < Arr->Neff; i++)
    {
        if (i == Arr->Neff-1) {
            printf("Barang tidak ditemukan\n");
        }
        else if (strcmp(Arr->Isi->name,Item)==0) {
            DeleteAt(Arr, i);
            printf("Barang dengan nama %s telah dihapus\n", Item);
            break;
        }
    }
}