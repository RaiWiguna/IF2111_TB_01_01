#include <stdio.h>
#include <stdlib.h>

#include "scanfile.h"

void ReadFile(FILE *file,ArrayDin *item, ArrayDin *UserItem, List *Account){
    if (file == NULL) {
        printf("Error: File tidak dapat dibuka.\n");
    }
    ReadItem(file,item);
    ReadUser(file,Account,UserItem);
}

void ReadItem(FILE *file,ArrayDin *Item){
    // Kamus Lokal 
    int n;

    // Algoritma
    (*Item).Neff = 0;
    STARTWORD_Item(file);
    n  = atoi(CurrentWord1.TabWord);
    for(int i =0; i<n;i++){
        STARTWORD_Item(file);
        InsertLastArrDin(Item,CurrentWord1.TabWord,CurrentWord2.TabWord);
    }
}

void ReadUser(FILE *file,List *Account,ArrayDin *UserItem){
    // Kamus Lokal 
    int n;
    int loop;
    // Algorima  

    STARTWORD_Looping(file);
    n = atoi(CurrentWordStringToInteger.TabWord);
    for(int i=0; i<n ;i++){
        STARTWORD_User(file);
        InsertLastList(Account,CurrentWord3.TabWord,CurrentWord4.TabWord,CurrentWord5.TabWord);
        
        STARTWORD_Looping(file);
        loop = atoi(CurrentWordStringToInteger.TabWord);
        Skip_Looping(file,loop);

        STARTWORD_Looping(file);
        loop = atoi(CurrentWordStringToInteger.TabWord);
        Skip_Looping(file,loop);
    }
}

void CreateUserWhislist(FILE *file, ListLinier *Whistlist,Word LoginAccount){
    // Kamus Lokal
    int n;
    int loop;

    // Algoritma
    rewind(file);
    STARTWORD_Looping(file);
    loop = atoi(CurrentWordStringToInteger.TabWord);
    Skip_Looping(file,loop);

    STARTWORD_Looping(file);
    n = atoi(CurrentWordStringToInteger.TabWord);
    for(int i=0; i<n ;i++){
        STARTWORD_User(file);
        if(IsSame(CurrentWord4.TabWord,LoginAccount.TabWord)){
            STARTWORD_Looping(file);
            loop = atoi(CurrentWordStringToInteger.TabWord);
            Skip_Looping(file,loop);

            STARTWORD_Looping(file);
            loop = atoi(CurrentWordStringToInteger.TabWord);
            for(int i=0;i<loop;i++){
                STARTWORD_WithBlank(file);
                InsVLastListLin(Whistlist,CurrentWordWithBlank.TabWord);
            }
            break;
        }
        else{
            STARTWORD_Looping(file);
            loop = atoi(CurrentWordStringToInteger.TabWord);
            Skip_Looping(file,loop);

            STARTWORD_Looping(file);
            loop = atoi(CurrentWordStringToInteger.TabWord);
            Skip_Looping(file,loop);
        }
    }
}

void CreateUserItem(FILE *file,ArrayDin *UserItem, Word LoginAccount){
    // Kamus Lokal 
    int n;
    int loop;
    // Algorima  

    rewind(file);
    STARTWORD_Looping(file);
    loop = atoi(CurrentWordStringToInteger.TabWord); // Melakukan skip pada file item yang ada pada game
    Skip_Looping(file,loop);

    STARTWORD_Looping(file);
    n = atoi(CurrentWordStringToInteger.TabWord);
    for(int i=0; i<n ;i++){
        STARTWORD_User(file);
        if(IsSame(CurrentWord4.TabWord,LoginAccount.TabWord)){
            ReadItem(file,UserItem);
            break;
        }
        else{
            STARTWORD_Looping(file);
            loop = atoi(CurrentWordStringToInteger.TabWord);
            Skip_Looping(file,loop);

            STARTWORD_Looping(file);
            loop = atoi(CurrentWordStringToInteger.TabWord);
            Skip_Looping(file,loop);
        }
    }
}

void WriteFile(FILE *file);

// void storeList(ArrayDin Item){
//     if(Item.Neff == 0){
//         printf("TOKO KOSONG\n");
//     }
//     else{
//         printf("List barang yang ada di toko :\n");
//         CetakNameArrayDin(Item);
//     }
// }

// void storeRequest(Queue *Req, ArrayDin Item) {
//     string input;
//     printf("Nama barang yang diminta: ");
//     STARTWORD();
//     StrcpyToString(input, &CurrentWord);  // Salin kata yang diminta

//     // Pastikan item tidak ada di antrian dan toko
//     if (!IsInQueue(Req, input) && !IsInArrDin(Item, input)) {
//         enqueue(Req, input);  // Enqueue item jika tidak ada duplikasi
//     } else if (IsInArrDin(Item, input)) {
//         printf("Barang dengan nama yang sama sudah ada di toko!\n");
//     } else {
//         printf("Barang dengan nama yang sama sudah ada di antrian!\n");
//     } 
// }

// void storeSupply(Queue Req, ArrayDin *Item) {
//     string temp;
//     string price;
//     Word input;

//     dequeue(&Req, &temp);
//     printf("Apakah kamu ingin menambahkan barang %s: ", temp);
//     STARTWORD();  
//     StrcpyToWord(&input, CurrentWord.TabWord);  
//     if (IsSame(input.TabWord, "Terima")) {
//         printf("Harga barang: ");
//         STARTWORD();  
//         StrcpyToString(price, &CurrentWord);
//         printf("%s\n",price);
//         InsertLastArrDin(Item, price, temp); 
//         printf("%s dengan harga %s telah ditambahkan ke toko.\n", temp, price);
//     } 
//     else if (IsSame(input.TabWord, "Tunda")) {
//         printf("%s dikembalikan ke antrian.\n", temp);
//         enqueue(&Req, temp); 
//     } 
//     else if (IsSame(input.TabWord, "Tolak")) {
//         printf("%s dihapuskan dari antrian.\n", temp);  // Tidak ada tindakan tambahan
//     } 
//     else if (IsSame(input.TabWord, "Purry")) {
//         printf(" < Balik ke menu >\n");
//     } 
// }

// void storeRemove(ArrayDin *Item){
//     // Kamus Lokal
//     Word input;
//     int index;
//     // Algoritma
//     printf("Nama barang yang akan dihapus: ");
//     STARTWORD();
//     StrcpyToWord(&input,CurrentWord.TabWord);
//     printf("\n");
//     if(IsInArrDin(*Item,input.TabWord)){
//         index = SearchArrDin(*Item,input.TabWord);
//         DeleteAtArrDin(Item,index);
//         printf("%s telah berhasil dihapus.\n",input.TabWord);
//     }
//     else{
//         printf("Toko tidak menjual %s.\n",input.TabWord);
//     }
// }
