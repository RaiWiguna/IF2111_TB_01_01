#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "menu.h"
#include "console.h"

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
    int Money = 50;

    CreateQueue(&permintaan);
    MakeArrayDin(&Item);
    MakeArrayDin(&UserItem);
    CreateEmptyListLin(&Whistlist);

    // Algoritma
    StrcpyToWord(&LoginAccount,"admin");
    Start(&file,&Item);
    // Load(&file);
    ReadFile(file,&Item,&UserItem,&Account);
    CetakArrayDin(Item);
    // Login(&LoginAccount,Account,&Money);
    
    // CreateUserItem(file,&UserItem,LoginAccount);
    // CreateUserWhislist(file,&Whistlist,LoginAccount);
    // // wishlistAdd(&Whistlist,Item);
    // PrintInfoListLin(Whistlist);
    // int i =1,j=2;
    // wishlistSwap(&Whistlist,i,j);
    // PrintInfoListLin(Whistlist);
    // wishlistRemoveNumber(&Whistlist,j);
    // PrintInfoListLin(Whistlist);
    // wishlistRemove(&Whistlist);
    // PrintInfoListLin(Whistlist);
    // wishlistClear(&Whistlist);
    // wishlistShow(Whistlist);
    // CetakArrayDin(UserItem);

    // storeList(Item);
    // enqueue(&permintaan,"ak47");
    // enqueue(&permintaan,"km45");
    // displayQueue(permintaan);
    // storeRequest(&permintaan,Item);
    // storeRequest(&permintaan,Item);
    // storeSupply(&permintaan, &Item);
    // displayQueue(permintaan);
    // CetakArrayDin(Item);
    // storeRemove(&Item);

    // Logout(&LoginAccount,&UserItem,&Whistlist);
    // Register(&LoginAccount,&Account);
    
    // Logout(&LoginAccount,&UserItem,&Whistlist);
    // StrcpyToWord(&LoginAccount,"User1");
    // CreateUserWhislist(file,&Whistlist,LoginAccount);
    // PrintInfoListLin(Whistlist);

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
