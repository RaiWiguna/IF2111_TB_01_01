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

int main(){
    ArrayDin Item;
    ReadFile("../../../save/ListBarang.txt",&Item);
    //storeList(Item);
    storeRequest(Item);

}


