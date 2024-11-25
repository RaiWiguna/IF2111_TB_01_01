#include <stdio.h>
#include <stdlib.h>

#include "scanfile.h"
#include "../Queue/queue.h"

void ReadFile(const char *filePath,ArrayDin *item){
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Error: File tidak dapat dibuka.\n");
    }
    ReadItem(file,item);
}

void ReadItem(FILE *file,ArrayDin *Item){
    // Kamus Lokal 
    int n;
    // Algoritma
    MakeArrayDin(Item);
    
    STARTWORD_Item(file);
    n  = atoi(CurrentWord1.TabWord);
    for(int i =0; i<n;i++){
        STARTWORD_Item(file);
        InsertLastArrDin(Item,CurrentWord1.TabWord,CurrentWord2.TabWord);
    }
}
void ReadUser(FILE *file);/*
Membaca bagian item pada user;
*/

void WriteFile(FILE *file);

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
    StrcpyToString(input, &CurrentWord);  // Salin kata yang diminta
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


int main(){
    ArrayDin Item;
    Queue permintaan;
    CreateQueue(&permintaan);
    ReadFile("../../../save/ListBarang.txt",&Item);


    //storeList(Item);
    enqueue(&permintaan,"kamu");
    enqueue(&permintaan,"saya");
    enqueue(&permintaan,"kami");
    enqueue(&permintaan,"anda");
    CetakArrayDin(Item);
    printf("\n");
    // storeSupply(permintaan,&Item);
    storeRemove(&Item);
    CetakArrayDin(Item);
}


