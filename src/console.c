#include <stdio.h>
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

void Login(Word *LoginAccount,List L){
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
            StrcpyToWord(LoginAccount, Username.TabWord);
            InsertLastList(L,Username.TabWord,Password.TabWord,"0");
            printf("Akun dengan username %s telah berhasil dibuat. Silahkan LOGIN untuk melanjutkan.\n",
            Username.TabWord);
        }
    }
}



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
//     StrcpyToString(&input, &CurrentWord);  // Salin kata yang diminta
//     printf("%s input\n", input);

//     // Pastikan item tidak ada di antrian dan toko
//     if (!IsInQueue(Req, input) && !IsInArrDin(Item, input)) {
//         enqueue(Req, input);  // Enqueue item jika tidak ada duplikasi
//     } else if (IsInArrDin(Item, input)) {
//         printf("Barang dengan nama yang sama sudah ada di toko!\n");
//     } else {
//         printf("Barang dengan nama yang sama sudah ada di antrian!\n");
//     }
//     displayQueue(*Req);  // Tampilkan antrian setelah penambahan
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