#include "linkedlist.h"

void CreateList(LinkedList *L) {
    First(*L) = NIL;
    Last(*L) = NIL;
}

Address Allocate(ElementType X) {
    Address P = (Node*)malloc(sizeof(Node));
    if (P != NIL) {
        Info(P) = X;
        Next(P) = NIL;
        Prev(P) = NIL;
    }
    return P;
}

bool IsListEmpty(LinkedList L) {
    return First(L) == NIL;
}

void InsertLast(LinkedList *L, ElementType X) {
    Address P = Allocate(X);
    if (P != NIL) {
        if (IsListEmpty(*L)) {
            First(*L) = P;
            Last(*L) = P;
        } else {
            Prev(P) = Last(*L);
            Next(Last(*L)) = P;
            Last(*L) = P;
        }
    }
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

void DeleteNode(LinkedList *L, Address P) {
    if (P == NIL) return;

    if (P == First(*L)) {
        First(*L) = Next(P);
        if (First(*L) != NIL) Prev(First(*L)) = NIL;
    } else if (P == Last(*L)) {
        Last(*L) = Prev(P);
        if (Last(*L) != NIL) Next(Last(*L)) = NIL;
    } else {
        Next(Prev(P)) = Next(P);
        Prev(Next(P)) = Prev(P);
    }
    free(P);
}
