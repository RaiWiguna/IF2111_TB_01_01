#include <stdio.h>
#include <stdlib.h>

#include "console.h"

void Start(FILE **file,ArrayDin *Item){
    // Algoritma
    *file = fopen("../save/default.txt","r");
    if(*file != NULL){
        printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
        ReadItem(*file,Item);
    }   

}
void Load(FILE **file){
    // Kamus Lokal
    Word tempWord;
    char filePath[200];

    // Algoritma Meminta Input
    printf(">> LOAD ");
    STARTWORD();

    // membaca file
    sprintf(filePath,"../save/%s",CurrentWord.TabWord);
    *file = fopen(filePath, "r");
    if(*file != NULL){
        printf("File %s berhasil di load.\n",CurrentWord.TabWord);
    }
}

void Login(Word *LoginAccount,List L, int *Money){
    // Kamus Lokal
    Word Username,Password;
    boolean Condition;
    int length = Length(L);
    int i=0;

    // Algoritma
    if((*LoginAccount).Length != 0){
        printf("Lakukan logout dari Akun %s terlebih dahulu.\n",(*LoginAccount).TabWord);
    }
    else{
        printf("Username :");
        STARTWORD();
        StrcpyToWord(&Username,CurrentWord.TabWord);

        printf("Password :");
        STARTWORD();
        StrcpyToWord(&Password,CurrentWord.TabWord);

        while(i<length && !Condition){
            if(IsSame(L.Account[i].name,Username.TabWord)){
                Condition = true;
                i = i-1;
            }
            i++;
        }
        if(!Condition){
            printf("Username belum terdaftar atau salah.\n");
        }
        else{
            if(!IsSame(L.Account[i].password,Password.TabWord)){
                printf("Password yang anda masukkan salah.\n");
            }
            else{
                StrcpyToWord(LoginAccount,Username.TabWord);
                *Money = (L.Account[i].money);
                printf("Login ke akun %s berhasil.\n",Username);
            }
        }
    }
}

void Logout(Word *LoginAccount, ArrayDin *UserItem, ListLinier *Whistlist){
    (*LoginAccount).Length=0;
    MakeArrayDin(UserItem);
    CreateEmptyListLin(Whistlist);
}

void Register(Word *LoginAccount, List *L){
    // Kamus Lokal
    Word Username,Password;
    boolean Condition; // True apabila akun belum ada pada data.txt
    int length = Length(*L);
    int i=0;

    // Algoritma
    if((*LoginAccount).Length != 0){
        printf("Lakukan logout dari Akun %s terlebih dahulu sebelum melakukan register.\n",(*LoginAccount).TabWord);
    }
    else{
        printf(">> REGISTER\n");
        printf("Username :");
        STARTWORD();
        StrcpyToWord(&Username,CurrentWord.TabWord);

        printf("Password :");
        STARTWORD();
        StrcpyToWord(&Password,CurrentWord.TabWord);

        while(i<length && !Condition){
            if(IsSame((*L).Account[i].name,Username.TabWord)){
                Condition = true;
            }
            i++;
        }
        if(Condition){
            printf("Akun dengan username %s gagal dibuat, Akun %s telah terdaftar pada database.\n",
            Username.TabWord,Username.TabWord);
        }
        else{
            InsertLastList(L,Username.TabWord,Password.TabWord,"0");
            printf("Akun dengan username %s telah berhasil dibuat. Silahkan LOGIN untuk melanjutkan.\n",
            Username.TabWord);
        }
    }
}

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
    // Kamus Lokal
    Word input;

    // Algoritma
    printf("Nama barang yang diminta: ");
    STARTWORD();
    StrcpyToWord(&input, CurrentWord.TabWord);  // Salin kata yang diminta

    // Pastikan item tidak ada di antrian dan toko
    if (!IsInQueue(*Req, input) && !IsInArrDin(Item, input.TabWord)) {
        enqueue(Req, input);  // Enqueue item jika tidak ada duplikasi
    } else if (IsInArrDin(Item, input.TabWord)) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
    } else {
        printf("Barang dengan nama yang sama sudah ada di antrian!\n");
    }
}

void storeSupply(Queue *Req, ArrayDin *Item) {
    Word input,temp,price;

    dequeue(Req, &temp);
    printf("Apakah kamu ingin menambahkan barang %s: ", temp.TabWord);
    STARTWORD();  
    StrcpyToWord(&input, CurrentWord.TabWord);  
    if (IsSame(input.TabWord, "Terima")) {
        printf("Harga barang: ");
        STARTWORD();  
        StrcpyToWord(&price, CurrentWord.TabWord);
        InsertLastArrDin(Item, price.TabWord, temp.TabWord); 
        printf("%s dengan harga %s telah ditambahkan ke toko.\n", temp.TabWord, price.TabWord);
    } 
    else if (IsSame(input.TabWord, "Tunda")) {
        printf("%s dikembalikan ke antrian.\n", temp);
        enqueue(Req, temp); 
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

void wishlistAdd(ListLinier *L, ArrayDin Item) {
    // Kamus Lokal
    Word item;

    // Algoritma
    printf("Masukkan nama barang: ");
    STARTWORD();
    StrcpyToWord(&item,CurrentWord.TabWord);

    address_list temp = First(*L);

    // Cari apakah barang sudah ada di wishlist
    if(!IsInListLin(*L,CurrentWord.TabWord)){
        if(IsInArrDin(Item,CurrentWord.TabWord)){
            InsVLastListLin(L,CurrentWord.TabWord);
            printf("Berhasil menambahkan %s ke wishlist!\n",CurrentWord.TabWord);
        }
        else{
            printf("Tidak ada barang dengan nama %s!\n",CurrentWord.TabWord);
        }
    }
    else{
        printf("%s sudah ada di wishlist!\n",CurrentWord.TabWord);
    }
}

void wishlistSwap(ListLinier *L, int i, int j) {
    // Kamus Lokal
    int bigger,smaller;
    address_list Pi,Pj;
    Word Temp1, Temp2;
    int index = 0;

    // Algoritma
    if (i == j) {
        printf("Gagal menukar posisi, posisi ke-%d dan ke-%d adalah sama.\n", i, j);
        return;
    }

    // Cari posisi/alamat dari yang indin ditukar
    Pi = SearchListLinIdx(*L,i);
    Pj = SearchListLinIdx(*L,j);

    if (Pi == NilList || Pj == NilList) {
        printf("Gagal menukar posisi! Salah satu indeks tidak valid.\n");
    } else {
        StrcpyToWord(&Temp1,Info(Pi));
        StrcpyToWord(&Temp2,Info(Pj));
        StrcpyToString(Info(Pi),&Temp2);
        StrcpyToString(Info(Pj),&Temp1);
        printf("Berhasil menukar posisi %s dengan %s pada wishlist!\n", Info(Pi), Info(Pj));
    }
}

void wishlistRemoveNumber(ListLinier *L, int index) {
    // Kamus Lokal
    address_list p;
    Word Temp;
    int currentIndex = 1;

    // Algoritma
    if (IsEmptyListLin(*L)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }
    // Cari elemen di posisi index
    p = SearchListLinIdx(*L,index);

    if (p == NilList) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", index);
    } else {
        StrcpyToWord(&Temp,Info(p));
        DelPListLin(L,Temp.TabWord);
    }
}

void wishlistRemove(ListLinier *L) {
    // Kamus Lokal
    Word item;
    address_list temp;

    // Algoritma
    printf("Masukkan nama barang yang akan dihapus: ");
    STARTWORD();
    StrcpyToWord(&item,CurrentWord.TabWord);
    // Cari Barang
    temp = SearchListLin(*L,item.TabWord);
    if(temp == NilList){
        printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", item);
    }
    else{
        DelPListLin(L,item.TabWord);
        printf("%s berhasil dihapus dari WISHLIST!\n",item.TabWord);
    }
}

void wishlistClear(ListLinier *L) {
    address_list P;
    while (!IsEmptyListLin(*L)) {
        DelFirstListLin(L, &P);
        DealokasiListLin(&P);
    }
    printf("Wishlist telah dikosongkan.\n");
}

void wishlistShow(ListLinier L) {
    if (IsEmptyListLin(L)) {
        printf("Wishlist kamu kosong!\n");
    } else {
        PrintInfoListLin(L);
    }
}