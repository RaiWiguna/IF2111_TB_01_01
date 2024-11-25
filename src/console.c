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

Queue storeRequest(ArrayDin Item){
    // Kamus Lokal
    Queue Req;
    CreateQueue(&Req);
    // Algoritma
    printf("Nama barang yang diminta: ");
    STARTWORD();
    if(!IsInQueue(Req,CurrentWord.TabWord)&& !IsInArrDin(Item,CurrentWord.TabWord)){
        enqueue(&Req,CurrentWord.TabWord);
    }
    else if(IsInArrDin(Item,CurrentWord.TabWord)){
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
    }
    else{
        printf("Barang dengan nama yang sama sudah ada di antrian!\n");
    }
    return (Req);
}