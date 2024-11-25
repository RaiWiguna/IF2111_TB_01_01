#include <stdio.h>
#include "console.h"

void storeList(ArrayDin Item){
    if(Item.Neff == 0){
        printf("TOKO KOSONG\n");
    }
    else{
        printf("List barang yang ada di toko :\n");
        CetakNameArrayDin(Item);
    }
}