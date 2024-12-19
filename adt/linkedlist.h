#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define NIL NULL

// Struktur Item
typedef struct {
    char name[50];
    int quantity;
} Item;

typedef Item ElementType;

typedef struct Node *Address;

typedef struct Node {
    ElementType info;
    Address next;
    Address prev;
} Node;

typedef struct {
    Address first;
    Address last;
} LinkedList;

// Makro akses
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).first)
#define Last(L) ((L).last)

// Fungsi prototipe
void CreateList(LinkedList *L);
bool IsListEmpty(LinkedList L);
Address SearchList(LinkedList L, char *name);
void InsertLast(LinkedList *L, ElementType X);
void DeleteNode(LinkedList *L, Address P);

#endif
