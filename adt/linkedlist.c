#include "linkedlist.h"
#include <stdio.h>

// Membuat list kosong
void CreateList(LinkedList *L) {
    FirstL(*L) = NIL;
    LastL(*L) = NIL;
}

// Mengecek apakah list kosong
bool IsListEmpty(LinkedList L) {
    return FirstL(L) == NIL && LastL(L) == NIL;
}

// Alokasi node baru
Address Allocate(ElementType X) {
    Address P = (Node*)malloc(sizeof(Node));
    if (P != NIL) {
        InfoL(P) = (char*)malloc((strlen(X) + 1) * sizeof(char));
        if (InfoL(P) != NIL) {
            strcpy(InfoL(P), X);
            NextL(P) = NIL;
            PrevL(P) = NIL;
        } else {
            free(P); // Gagal alokasi InfoL
            P = NIL;
        }
    }
    return P;
}

// Dealokasi node
void Deallocate(Address P) {
    if (P != NIL) {
        free(InfoL(P));
        free(P);
    }
}

// Menambahkan node di awal
void InsertFirstL(LinkedList *L, Address P) {
    if (IsListEmpty(*L)) {
        FirstL(*L) = P;
        LastL(*L) = P;
    } else {
        NextL(P) = FirstL(*L);
        PrevL(FirstL(*L)) = P;
        FirstL(*L) = P;
    }
}

// Menambahkan node di akhir
void InsertLastL(LinkedList *L, Address P) {
    if (IsListEmpty(*L)) {
        FirstL(*L) = P;
        LastL(*L) = P;
    } else {
        PrevL(P) = LastL(*L);
        NextL(LastL(*L)) = P;
        LastL(*L) = P;
    }
}

// Menghapus node dari awal
void DeleteFirstL(LinkedList *L, Address *P) {
    *P = FirstL(*L);
    if (FirstL(*L) == LastL(*L)) {
        FirstL(*L) = NIL;
        LastL(*L) = NIL;
    } else {
        FirstL(*L) = NextL(FirstL(*L));
        PrevL(FirstL(*L)) = NIL;
    }
    NextL(*P) = NIL;
}

// Menghapus node dari akhir
void DeleteLastL(LinkedList *L, Address *P) {
    *P = LastL(*L);
    if (FirstL(*L) == LastL(*L)) {
        FirstL(*L) = NIL;
        LastL(*L) = NIL;
    } else {
        LastL(*L) = PrevL(LastL(*L));
        NextL(LastL(*L)) = NIL;
    }
    PrevL(*P) = NIL;
}

// Mencari elemen di dalam list
Address Search(LinkedList L, ElementType X) {
    Address P = FirstL(L);
    while (P != NIL) {
        if (strcmp(InfoL(P), X) == 0) {
            return P;
        }
        P = NextL(P);
    }
    return NIL;
}

// Mencetak list ke depan
void PrintListForward(LinkedList L) {
    Address P = FirstL(L);
    printf("[");
    while (P != NIL) {
        printf("%s", InfoL(P));
        if (NextL(P) != NIL) {
            printf(", ");
        }
        P = NextL(P);
    }
    printf("]\n");
}

// Mencetak list ke belakang
void PrintListBackward(LinkedList L) {
    Address P = LastL(L);
    printf("[");
    while (P != NIL) {
        printf("%s", InfoL(P));
        if (PrevL(P) != NIL) {
            printf(", ");
        }
        P = PrevL(P);
    }
    printf("]\n");
}

Address SearchList(LinkedList L, char *name) {
    Address P = First(L);
    while (P != NIL) {
        if (strcmp(Info(P).name, name) == 0) {
            return P;
        }
        P = Next(P);
    }
    return NIL;
}
