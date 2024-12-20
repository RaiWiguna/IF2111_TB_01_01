/* Program Main, untuk menjalankan fungsi secara keseluruhan */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "menu.h"
#include "console.h"
#include "ADT/Kustom/Kustom.h"

int main(){
    // Inisialisasi Program
    Word Input;
    FILE *file;
    ArrayDin Item;
    ArrayDin UserItem; // Ingat diganti menjadi stack
    Queue permintaan; 
    List Account = MakeList();
    
    User LoginAccount;
    boolean quit = false;
    boolean LoadFile = false;
    boolean IsLogin = false;

    CreateQueue(&permintaan);
    MakeArrayDin(&Item);
    MakeArrayDin(&UserItem);
    CreateEmptyListLin(&LoginAccount.wishlist);

    // Program
    //Welcomemenu();
    system("cls");
    while(!quit){
        printf(">> ");
        STARTWORD();
        StrcpyToWord(&Input,CurrentWord.TabWord);
        if(IsSame(Input.TabWord,"START")){
            Start(&file,&Item);
            LoadFile = true;
        }
        else if(IsSamePartial(Input.TabWord,"LOAD ")){
            // Kamus Lokal
            Word FileName;
            int min = Skip_Char(Input.TabWord,"LOAD ");
            int max = Input.Length;
            char buffer[100];

            //Proses Inisialiasi Input
            copyWordExact(&FileName,&Input,min,max); 

            Load(&file,FileName);
            ReadFile(file,&Item,&UserItem,&Account);
            LoadFile = true;
        }
        else if(IsSame(Input.TabWord,"HELP")){

        }
        else if(IsSame(Input.TabWord,"LOGIN")){
            if(!LoadFile){
                printf("Lakukan LOAD/START terlebih dahulu\n");
            }
            else{
                Login(&LoginAccount.name,Account,&LoginAccount.money);
                CreateUserItem(file,&UserItem,LoginAccount.name);
                CreateUserWhislist(file,&LoginAccount.wishlist,LoginAccount.name);
                IsLogin = true;
            }
        }
        else if(IsSame(Input.TabWord,"LOGOUT")){
            if(!LoadFile){
                printf("Lakukan LOAD/START terlebih dahulu\n");
            }
            else{
                Logout(&LoginAccount.name,&UserItem,&LoginAccount.wishlist);
            }
        }
        else if(IsSame(Input.TabWord,"REGISTER")){
            if(!LoadFile){
                printf("Lakukan LOAD/START terlebih dahulu.\n");
            }
            else{
                Register(&LoginAccount.name,&Account);
            }
        }
        else if(IsSame(Input.TabWord,"STORE LIST")){
            if(!IsLogin){
                printf("Lakukan LOGIN terlebih dahulu.\n");
            }
            else{
                storeList(Item);
            }
        }
        else if(IsSame(Input.TabWord,"STORE REQUEST")){
            if(!IsLogin){
                printf("Lakukan LOGIN terlebih dahulu.\n");
            }
            else{
                storeRequest(&permintaan,Item);
            }
        }
        else if(IsSame(Input.TabWord,"STORE SUPPLY")){
            if(!IsLogin){
                printf("Lakukan LOGIN terlebih dahulu.\n");
            }
            else{
                storeSupply(&permintaan,&Item);
            }
        }
        else if(IsSame(Input.TabWord,"STORE REMOVE")){
            if(!IsLogin){
                printf("Lakukan LOGIN terlebih dahulu.\n");
            }
            else{
                storeRemove(&Item);
            }
        }
        else if(IsSame(Input.TabWord,"WISHLIST ADD")){
            if(!IsLogin){
                printf("Lakukan LOGIN terlebih dahulu.\n");
            }
            else{
                wishlistAdd(&LoginAccount.wishlist,Item);
            }
        }
        else if(IsSamePartial(Input.TabWord,"WISHLIST SWAP ")){
            // Kamus Lokal
            Word indexInputI;
            Word indexInputJ;
            string indexCheckI;
            string indexCheckJ;

            int min = Skip_Char(Input.TabWord,"WISHLIST SWAP ");
            int max = Input.Length;
            int indexI;
            int indexJ;
            char bufferI[20];
            char bufferJ[20];

            //Proses Inisialiasi Input
            copyWordExactWithBlank(&indexInputI,&indexInputJ,&Input,min,max); 
            indexI = atoi(indexInputI.TabWord);
            indexCheckI = itoa(indexI,bufferI,10);
            indexJ = atoi(indexInputJ.TabWord);
            indexCheckJ = itoa(indexJ,bufferJ,10);
            
            //Proses pengecekan dan menjalankan fungsi
            if(IsSame(indexInputI.TabWord,indexCheckI) && IsSame(indexInputJ.TabWord,indexCheckJ)){
                if(!IsLogin){
                printf("Lakukan LOGIN terlebih dahulu.\n");
                }
                else{
                    wishlistSwap(&LoginAccount.wishlist,indexI,indexJ);
                }
            }
            else{
                HandleWrongInput();
            }
        }
        else if(IsSamePartial(Input.TabWord,"WISHLIST REMOVE ")){
            // Kamus Lokal
            Word indexInput;
            string indexCheck;
            int min = Skip_Char(Input.TabWord,"WISHLIST REMOVE ");
            int max = Input.Length;
            int index;
            char buffer[20];

            //Proses Inisialiasi Input
            copyWordExact(&indexInput,&Input,min,max);  
            index = atoi(indexInput.TabWord);
            indexCheck = itoa(index,buffer,10);

            //Algoritma Pengecekan serta Proses
            if(IsSame(indexInput.TabWord,indexCheck)){
                if(!IsLogin){
                printf("Lakukan LOGIN terlebih dahulu.\n");
            }
                else{
                    int i;
                    wishlistRemoveNumber(&LoginAccount.wishlist,index);
                }
            }
            else{
                HandleWrongInput();
            }
        }
        else if(IsSame(Input.TabWord,"WISHLIST REMOVE")){
            if(!IsLogin){
                printf("Lakukan LOGIN terlebih dahulu.\n");
            }
            else{
                wishlistRemove(&LoginAccount.wishlist);
            }
        }
        else if(IsSame(Input.TabWord,"WISHLIST CLEAR")){
            if(!IsLogin){
                printf("Lakukan LOGIN terlebih dahulu.\n");
            }
            else{
                wishlistClear(&LoginAccount.wishlist);
            }
        }
        else if(IsSame(Input.TabWord,"WISHLIST SHOW")){
            if(!IsLogin){
                printf("Lakukan LOGIN terlebih dahulu.\n");
            }
            else{
                wishlistShow(LoginAccount.wishlist);
            }
        }
        else if(IsSame(Input.TabWord,"QUIT")){
            quit = true;
        }
        else{
            printf("Command yang dimasukkan salah, jika bingung ketikkan \"HELP\".\n");
        }
    }
}