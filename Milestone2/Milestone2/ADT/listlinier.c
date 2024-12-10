#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsEmptyList(List L) {
    return (First(L) == NilList);
}

void CreateEmptyList(List *L) {
    First(*L) = NilList;
}

address_list AlokasiList(infotypelist X) {
    address_list P = (address_list)malloc(sizeof(ElmtList));
    if (P != NilList) {
        Info(P) = (char*)malloc((strlength(X) + 1) * sizeof(char));
        strcopy(Info(P), X);
        Next(P) = NilList;
    }
    return P;
}

void DealokasiList(address_list *P) {
    free(Info(*P));
    free(*P);
    *P = NilList;
}

address_list SearchList(List L, infotypelist X) {
    address_list P = First(L);
    while (P != NilList) {
        if (strcompare(Info(P), X) == 0) {
            return P;
        }
        P = Next(P);
    }
    return NilList;
}

void InsVFirst(List *L, infotypelist X) {
    address_list P = AlokasiList(X);
    if (P != NilList) {
        InsertFirst(L, P);
    }
}

void InsVLast(List *L, infotypelist X) {
    address_list P = AlokasiList(X);
    if (P != NilList) {
        InsertLast(L, P);
    }
}

void DelVFirst(List *L, infotypelist *X) {
    address_list P;
    DelFirst(L, &P);
    *X = Info(P);
    DealokasiList(&P);
}

void DelVLast(List *L, infotypelist *X) {
    address_list P;
    DelLast(L, &P);
    *X = Info(P);
    DealokasiList(&P);
}

void InsertFirst(List *L, address_list P) {
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(List *L, address_list P, address_list Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast(List *L, address_list P) {
    if (IsEmptyList(*L)) {
        InsertFirst(L, P);
    } else {
        address_list Last = First(*L);
        while (Next(Last) != NilList) {
            Last = Next(Last);
        }
        Next(Last) = P;
    }
}

void DelFirst(List *L, address_list *P) {
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = NilList;
}

void DelP(List *L, infotypelist X) {
    address_list P = First(*L);
    if (strcompare(Info(P), X) == 0) {
        DelFirst(L, &P);
        DealokasiList(&P);
    } else {
        address_list Prec = NilList;
        while (P != NilList && strcompare(Info(P), X) != 0) {
            Prec = P;
            P = Next(P);
        }
        if (P != NilList) {
            DelAfter(L, &P, Prec);
            DealokasiList(&P);
        }
    }
}

void DelLast(List *L, address_list *P) {
    if (Next(First(*L)) == NilList) {
        DelFirst(L, P);
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

void DelAfter(List *L, address_list *Pdel, address_list Prec) {
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = NilList;
}

void PrintInfo(List L) {
    address_list P = First(L);
    int id=1;
    printf("Berikut adalah isi wishlist: \n");
    while (P != NilList) {
        printf("%d. %s\n", id,Info(P));
        id++;
        P = Next(P);
    }
}

int NbElmtList(List L) {
    int count = 0;
    address_list P = First(L);
    while (P != NilList) {
        count++;
        P = Next(P);
    }
    return count;
}

infotypelist Max(List L) {
    address_list P = First(L);
    infotypelist max = Info(P);
    while (P != NilList) {
        if (strcompare(Info(P), max) > 0) {
            max = Info(P);
        }
        P = Next(P);
    }
    return max;
}

address_list AdrMax(List L) {
    address_list P = First(L);
    address_list maxAdr = P;
    infotypelist max = Info(P);
    while (P != NilList) {
        if (strcompare(Info(P), max) > 0) {
            max = Info(P);
            maxAdr = P;
        }
        P = Next(P);
    }
    return maxAdr;
}

infotypelist Min(List L) {
    address_list P = First(L);
    infotypelist min = Info(P);
    while (P != NilList) {
        if (strcompare(Info(P), min) < 0) {
            min = Info(P);
        }
        P = Next(P);
    }
    return min;
}

address_list AdrMin(List L) {
    address_list P = First(L);
    address_list minAdr = P;
    infotypelist min = Info(P);
    while (P != NilList) {
        if (strcompare(Info(P), min) < 0) {
            min = Info(P);
            minAdr = P;
        }
        P = Next(P);
    }
    return minAdr;
}

float Average(List L) {
    int sum = 0;
    int count = 0;
    address_list P = First(L);
    while (P != NilList) {
        sum += atoi(Info(P)); // Assuming Info(P) contains numeric strings
        count++;
        P = Next(P);
    }
    return (float)sum / count;
}

void InversList(List *L) {
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

void Konkat1(List *L1, List *L2, List *L3) {
    address_list Last1;
    CreateEmptyList(L3);
    if (IsEmptyList(*L1)) {
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