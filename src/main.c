#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "menu.h"
#include "ADT\ScanFile\scanfile.h"
#include "ADT\mesinkata\mesinkata.h"

int main(){
    // Kamus
    // FILE *file ;
    FILE *file = fopen("../save/ListBarang.txt","r");
    ArrayDin Item;
    ArrayDin UserItem;
    Queue permintaan; 
    List Account = MakeList();
    ListLinier Whistlist;
    Word LoginAccount;

    boolean login;
    CreateQueue(&permintaan);
    MakeArrayDin(&Item);
    MakeArrayDin(&UserItem);
    CreateEmptyListLin(&Whistlist);

    // Algoritma
    StrcpyToWord(&LoginAccount,"admin");
    // Load(&file,&login);
    ReadFile(file,&Item,&UserItem,&Account);
    // Login(&LoginAccount,Account);
    CreateUserItem(file,&UserItem,LoginAccount);
    CreateUserWhislist(file,&Whistlist,LoginAccount);
    PrintInfoListLin(Whistlist);
    // CetakArrayDin(UserItem);
    // printf("%d",LengthArrDin(UserItem));
    //storeList(Item);
    //Load(&Item,&Account,&login);
    //Start(login);
    //enqueue(&permintaan,"saya");
    // enqueue(&permintaan,"kami");
    // enqueue(&permintaan,"anda");
    // CetakArrayDin(Item);
    // printf("\n");
    //displayQueue(permintaan);
    //storeRemove(&Item);
    // CetakArrayDin(Item);
}
