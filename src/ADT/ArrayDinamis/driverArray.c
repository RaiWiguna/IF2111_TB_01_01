#include <stdio.h>
#include <stdlib.h>

#include "ArrayDinamis.h"
#include "../mesinkata/mesinkata.h"

int main(){
    ArrayDin tst;
    MakeArrayDin(&tst);
    InsertFirstArrDin(&tst,"aku");
    InsertFirstArrDin(&tst,"kamu");
    InsertFirstArrDin(&tst,"saya");
    InsertLastArrDin(&tst,"anda");
    InsertAtArrDin(&tst,"kami",2);

    printf("Isi ArrayDin:\n");
    CetakArrayDin(tst);
    printf("\n");
    DeleteFirstArrDin(&tst);
    DeleteAtArrDin(&tst,2);
    DeleteLastArrDin(&tst);
    printf("Isi ArrayDin update:\n");
    CetakArrayDin(tst);
    printf("%d indeks\n",SearchArrDin(tst,"kami"));
    printf("%s\n",GetInput(tst,1));

    DeallocateArrDin(&tst);
}