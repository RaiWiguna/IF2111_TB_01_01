#include <stdio.h>
#include <stdlib.h>

#include "listlinier.h"
#include "../ArrayDinamis/ArrayDinamis.h"
boolean IsEmptyListLin(ListLinier L) {
    return (First(L) == NilList);
}

void CreateEmptyListLin(ListLinier *L) {
    First(*L) = NilList;
}

address_list AlokasiListLin(infotypelist X) {
    address_list P = (address_list)malloc(sizeof(ElmtList));
    if (P != NilList) {
        Info(P) = (char*)malloc((strLength(X) + 1) * sizeof(char));
        copyString(Info(P), X);
        Next(P) = NilList;
    }
    return P;
}

void DealokasiListLin(address_list *P) {
    free(Info(*P));
    free(*P);
    *P = NilList;
}

address_list SearchListLin(ListLinier L, infotypelist X) {
    address_list P = First(L);
    while (P != NilList) {
        if (IsSame(Info(P), X)) {
            return P;
        }
        P = Next(P);
    }
    return NilList;
}

address_list SearchListLinIdx(ListLinier L, int index){
    // Kamus Lokal
    address_list P = First(L);
    int i=0;

    // Algoritma
    while (P != NilList && i<index) {
        if(i == (index-1)){
            return P;
        }
        P = Next(P);
        i++;
    }
    return NilList;
}
void InsVFirstListLin(ListLinier *L, infotypelist X) {
    address_list P = AlokasiListLin(X);
    if (P != NilList) {
        InsertFirstListLin(L, P);
    }
}

void InsVLastListLin(ListLinier *L, infotypelist X) {
    address_list P = AlokasiListLin(X);
    if (P != NilList) {
        InsertLastListLin(L, P);
    }
}

void DelVFirstListLin(ListLinier *L, infotypelist *X) {
    address_list P;
    DelFirstListLin(L, &P);
    *X = Info(P);
    DealokasiListLin(&P);
}

void DelVLastListLin(ListLinier *L, infotypelist *X) {
    address_list P;
    DelLastListLin(L, &P);
    *X = Info(P);
    DealokasiListLin(&P);
}

void InsertFirstListLin(ListLinier *L, address_list P) {
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfterListLin(ListLinier *L, address_list P, address_list Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLastListLin(ListLinier *L, address_list P) {
    if (IsEmptyListLin(*L)) {
        InsertFirstListLin(L, P);
    } else {
        address_list Last = First(*L);
        while (Next(Last) != NilList) {
            Last = Next(Last);
        }
        Next(Last) = P;
    }
}

void DelFirstListLin(ListLinier *L, address_list *P) {
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = NilList;
}

void DelPListLin(ListLinier *L, infotypelist X) {
    address_list P = First(*L);
    if (IsSame(Info(P), X)) {
        DelFirstListLin(L, &P);
        DealokasiListLin(&P);
    } else {
        address_list Prec = NilList;
        while (P != NilList && !IsSame(Info(P), X)) {
            Prec = P;
            P = Next(P);
        }
        if (P != NilList) {
            DelAfterListLin(L, &P, Prec);
            DealokasiListLin(&P);
        }
    }
}

void DelLastListLin(ListLinier *L, address_list *P) {
    if (Next(First(*L)) == NilList) {
        DelFirstListLin(L, P);
    } else {
        address_list Prec = NilList;
        address_list Last = First(*L);
        while (Next(Last) != NilList) {
            Prec = Last;
            Last = Next(Last);
        }
        *P = Last;
        Next(Prec) = NilList;
    }
}

void DelAfterListLin(ListLinier *L, address_list *Pdel, address_list Prec) {
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = NilList;
}

void PrintInfoListLin(ListLinier L) {
    address_list P = First(L);
    int id=1;
    printf("Berikut adalah isi wishlist-mu: \n");
    while (P != NilList) {
        printf("%d. %s\n", id,Info(P));
        id++;
        P = Next(P);
    }
}

int NbElmtListListLin(ListLinier L) {
    int count = 0;
    address_list P = First(L);
    while (P != NilList) {
        count++;
        P = Next(P);
    }
    return count;
}

// infotypelist MaxListLin(ListLinier L) {
//     address_list P = First(L);
//     infotypelist max = Info(P);
//     while (P != NilList) {
//         if (strcompare(Info(P), max) > 0) {
//             max = Info(P);
//         }
//         P = Next(P);
//     }
//     return max;
// }

// address_list AdrMaxListLin(ListLinier L) {
//     address_list P = First(L);
//     address_list maxAdr = P;
//     infotypelist max = Info(P);
//     while (P != NilList) {
//         if (strcompare(Info(P), max) > 0) {
//             max = Info(P);
//             maxAdr = P;
//         }
//         P = Next(P);
//     }
//     return maxAdr;
// }

// infotypelist MinListLin(ListLinier L) {
//     address_list P = First(L);
//     infotypelist min = Info(P);
//     while (P != NilList) {
//         if (strcompare(Info(P), min) < 0) {
//             min = Info(P);
//         }
//         P = Next(P);
//     }
//     return min;
// }

// address_list AdrMinListLin(ListLinier L) {
//     address_list P = First(L);
//     address_list minAdr = P;
//     infotypelist min = Info(P);
//     while (P != NilList) {
//         if (strcompare(Info(P), min) < 0) {
//             min = Info(P);
//             minAdr = P;
//         }
//         P = Next(P);
//     }
//     return minAdr;
// }

// float AverageListLin(ListLinier L) {
//     int sum = 0;
//     int count = 0;
//     address_list P = First(L);
//     while (P != NilList) {
//         sum += atoi(Info(P)); // Assuming Info(P) contains numeric strings
//         count++;
//         P = Next(P);
//     }
//     return (float)sum / count;
// }

void InversListListLin(ListLinier *L) {
    address_list P = First(*L);
    address_list Prec = NilList;
    address_list Succ;
    while (P != NilList) {
        Succ = Next(P);
        Next(P) = Prec;
        Prec = P;
        P = Succ;
    }
    First(*L) = Prec;
}

void Konkat1ListLin(ListLinier *L1, ListLinier *L2, ListLinier *L3) {
    address_list Last1;
    CreateEmptyListLin(L3);
    if (IsEmptyListLin(*L1)) {
        First(*L3) = First(*L2);
    } else {
        First(*L3) = First(*L1);
        Last1 = First(*L1);
        while (Next(Last1) != NilList) {
            Last1 = Next(Last1);
        }
        Next(Last1) = First(*L2);
    }
    First(*L1) = NilList;
    First(*L2) = NilList;
}

boolean IsInListLin(ListLinier L,infotypelist X){
    // Kamus Lokal
    boolean Found = false;

    // Algoritma
    address_list p = First(L);
    while (p != NilList && !Found) {
        if(IsSame(Info(p),X)){
            Found = true;
        }
        p = Next(p);
    }
    return Found;
}

// void wishlistAdd(ListLinier *L, ArrayDin Item) {
//     // Kamus Lokal
//     Word item;

//     // Algoritma
//     printf("Masukkan nama barang: ");
//     STARTWORD();
//     StrcpyToWord(&item,CurrentWord.TabWord);

//     address_list temp = First(*L);

//     // Cari apakah barang sudah ada di wishlist
//     if(!IsInListLin(*L,CurrentWord.TabWord)){
//         if(IsInArrDin(Item,CurrentWord.TabWord)){
//             InsVLastListLin(L,CurrentWord.TabWord);
//             printf("Berhasil menambahkan %s ke wishlist!\n",CurrentWord.TabWord);
//         }
//         else{
//             printf("Tidak ada barang dengan nama %s!\n",CurrentWord.TabWord);
//         }
//     }
//     else{
//         printf("%s sudah ada di wishlist!\n",CurrentWord.TabWord);
//     }
// }

// void wishlistSwap(LinkedList *L, int i, int j) {
//     if (i == j) {
//         printf("Gagal menukar posisi, posisi ke-%d dan ke-%d adalah sama.\n", i, j);
//         return;
//     }

//     Address Pi = FirstL(*L), Pj = FirstL(*L);
//     int index = 1;

//     // Cari elemen ke-i dan ke-j
//     while (Pi != NIL && index < i) {
//         Pi = NextL(Pi);
//         index++;
//     }
//     index = 1;
//     while (Pj != NIL && index < j) {
//         Pj = NextL(Pj);
//         index++;
//     }

//     if (Pi == NIL || Pj == NIL) {
//         printf("Gagal menukar posisi! Salah satu indeks tidak valid.\n");
//     } else {
//         ElementType temp = strdup(InfoL(Pi));
//         free(InfoL(Pi));
//         InfoL(Pi) = strdup(InfoL(Pj));
//         free(InfoL(Pj));
//         InfoL(Pj) = temp;

//         printf("Berhasil menukar posisi %s dengan %s pada wishlist!\n", InfoL(Pi), InfoL(Pj));
//     }
// }

// void wishlistRemoveNumber(LinkedList *L, int index) {
//     if (IsListEmpty(*L)) {
//         printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
//         return;
//     }

//     Address P = FirstL(*L);
//     int currentIndex = 1;

//     // Cari elemen di posisi index
//     while (P != NIL && currentIndex < index) {
//         P = NextL(P);
//         currentIndex++;
//     }

//     if (P == NIL) {
//         printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", index);
//     } else {
//         printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", index);
//         if (P == FirstL(*L)) {
//             DeleteFirstL(L, &P);
//         } else if (P == LastL(*L)) {
//             DeleteLastL(L, &P);
//         } else {
//             NextL(PrevL(P)) = NextL(P);
//             PrevL(NextL(P)) = PrevL(P);
//         }
//         Deallocate(P);
//     }
// }

// void wishlistRemove(LinkedList *L) {
//     char* item;

//     printf("Masukkan nama barang yang akan dihapus: ");
//     STARTWORD();
//     item = CurrentWord.TabWord;

//     Address temp = FirstL(*L);

//     // Cari elemen berdasarkan item
//     while (temp != NIL) {
//         if (strcmp_custom(InfoL(temp), item) == 0) {
//             // Hapus elemen dari list
//             if (temp == FirstL(*L)) {
//                 DeleteFirstL(L, &temp);
//             } else if (temp == LastL(*L)) {
//                 DeleteLastL(L, &temp);
//             } else {
//                 NextL(PrevL(temp)) = NextL(temp);
//                 PrevL(NextL(temp)) = PrevL(temp);
//             }
//             printf("%s berhasil dihapus dari WISHLIST!\n", item);
//             Deallocate(temp); // Dealokasi memori
//             return;
//         }
//         temp = NextL(temp);
//     }

//     // Jika barang tidak ditemukan
//     printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", item);
// }

// void wishlistClear(LinkedList *L) {
//     Address P;
//     while (!IsListEmpty(*L)) {
//         DeleteFirstL(L, &P);
//         Deallocate(P);
//     }
//     printf("Wishlist telah dikosongkan.\n");
// }

// void wishlistShow(LinkedList L) {
//     if (IsListEmpty(L)) {
//         printf("Wishlist kamu kosong!\n");
//     } else {
//         printf("Berikut adalah isi wishlist-mu:\n");
//         Address P = FirstL(L);
//         int index = 1;
//         while (P != NIL) {
//             printf("%d. %s\n", index, InfoL(P));
//             P = NextL(P);
//             index++;
//         }
//     }
// }

// int main(){
//     // Kamus Lokal
//     ListLinier L;

//     // Algoritma
//     CreateEmptyListLin(&L);
//     InsVLastListLin(&L,"mesinkata");
//     PrintInfoListLin(L);

//     // Test Searh 
//     printf("%d",IsInListLin(L,"mesinkata"));
//     SearchListLinIdx(L,1);
// }