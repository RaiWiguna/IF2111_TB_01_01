/* Program Main, untuk menjalankan fungsi secara keseluruhan */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "menu.h"
#include "console.h"

int main(){
    // Inisialisasi Program
    Word Input;
    FILE *file;
    ArrayDin Item;
    ArrayDin UserItem;
    Queue permintaan; 
    List Account = MakeList();
    ListLinier Wishlist;
    Word LoginAccount;
    int Money;
    boolean quit = false;
    boolean LoadFile;

    CreateQueue(&permintaan);
    MakeArrayDin(&Item);
    MakeArrayDin(&UserItem);
    CreateEmptyListLin(&Wishlist);

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
        else if(IsSame(Input.TabWord,"LOAD")){
            Load(&file);
            ReadFile(file,&Item,&UserItem,&Account);
            LoadFile = true;
        }
        else if(IsSame(Input.TabWord,"HELP")){

        }
        else if(IsSame(Input.TabWord,"QUIT")){
            quit = true;
        }

        else if(IsSame(Input.TabWord,"LOGIN")){
            if(!LoadFile){
                printf("Lakukan LOAD/START terlebih dahulu\n");
            }
            else{
                Login(&LoginAccount,Account,&Money);
                CreateUserItem(file,&UserItem,LoginAccount);
                CreateUserWhislist(file,&Wishlist,LoginAccount);
            }
        }
        else if(IsSame(Input.TabWord,"LOG OUT")){
            if(!LoadFile){
                printf("Lakukan LOAD/START terlebih dahulu\n");
            }
            else{
                Logout(&LoginAccount,&UserItem,&Wishlist);
            }
        }
        else if(IsSame(Input.TabWord,"REGISTER")){
            if(!LoadFile){
                printf("Lakukan LOAD/START terlebih dahulu\n");
            }
            else{
                Register(&LoginAccount,&Account);
            }
            CetakList(Account);
        }
    }
}