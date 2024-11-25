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

void storeRequest(Queue *Req, ArrayDin Item) {
    string input;
    printf("Nama barang yang diminta: ");
    STARTWORD();
    StrcpyToString(&input, &CurrentWord);  // Salin kata yang diminta
    printf("%s input\n", input);

    // Pastikan item tidak ada di antrian dan toko
    if (!IsInQueue(Req, input) && !IsInArrDin(Item, input)) {
        enqueue(Req, input);  // Enqueue item jika tidak ada duplikasi
    } else if (IsInArrDin(Item, input)) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
    } else {
        printf("Barang dengan nama yang sama sudah ada di antrian!\n");
    }
    displayQueue(*Req);  // Tampilkan antrian setelah penambahan
}

void storeSupply(Queue Req, ArrayDin *Item) {
    string temp;
    string price;
    Word input;

    dequeue(&Req, &temp);
    printf("Apakah kamu ingin menambahkan barang %s: ", temp);
    STARTWORD();  
    StrcpyToWord(&input, CurrentWord.TabWord);  
    if (IsSame(input.TabWord, "Terima")) {
        printf("Harga barang: ");
        STARTWORD();  
        StrcpyToString(price, &CurrentWord);
        InsertLastArrDin(Item, price, temp); 
        printf("%s dengan harga %s telah ditambahkan ke toko.\n", temp, price);
    } 
    else if (IsSame(input.TabWord, "Tunda")) {
        printf("%s dikembalikan ke antrian.\n", temp);
        enqueue(&Req, temp); 
    } 
    else if (IsSame(input.TabWord, "Tolak")) {
        printf("%s dihapuskan dari antrian.\n", temp);  // Tidak ada tindakan tambahan
    } 
    else if (IsSame(input.TabWord, "Purry")) {
        printf(" < Balik ke menu >\n");
    } 
}

void storeRemove(ArrayDin *Item){
    // Kamus Lokal
    Word input;
    int index;
    // Algoritma
    printf("Nama barang yang akan dihapus: ");
    STARTWORD();
    StrcpyToWord(&input,CurrentWord.TabWord);
    printf("\n");
    if(IsInArrDin(*Item,input.TabWord)){
        index = SearchArrDin(*Item,input.TabWord);
        DeleteAtArrDin(Item,index);
        printf("%s telah berhasil dihapus.\n",input.TabWord);
    }
    else{
        printf("Toko tidak menjual %s.\n",input.TabWord);
    }
}