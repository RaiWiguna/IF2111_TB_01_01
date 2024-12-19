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