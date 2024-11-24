#include <stdio.h>
#include <stdlib.h>

#include "scanfile.h"

void ReadFile(const char *filePath){
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Error: File tidak dapat dibuka.\n");
    }
    ReadItem(file);
}

void ReadItem(FILE *file){
    // Kamus Lokal 
    int n;
    ArrayDin Price, Item;
    // Algoritma
    MakeArrayDin(&Price);
    MakeArrayDin(&Item);
    
    STARTWORD_Item(file);
    n  = atoi(CurrentWord1.TabWord);
    printf("%d jumlah baris\n",n);
    for(int i =0; i<n;i++){
        STARTWORD_Item(file);
        InsertLastArrDin(&Price,CurrentWord1.TabWord);
        InsertLastArrDin(&Item,CurrentWord2.TabWord);

    }
    printf("\n");
    CetakArrayDin(Price);
    CetakArrayDin(Item);
    
}
void ReadUser(FILE *file);/*
Membaca bagian item pada user;
*/

void WriteFile(FILE *file);

int main(){
    ReadFile("../../../save/ListBarang.txt");
}