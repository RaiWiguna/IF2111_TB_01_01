/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address_list dengan pointer */
/* infotypelist adalah string (nama barang) */

#ifndef listlinier_H
#define listlinier_H

#include "boolean.h"
#include "mesinkata.h"

#define NilList NULL

typedef char* infotypelist;
typedef struct tElmtlist *address_list;
typedef struct tElmtlist
{
    infotypelist info;
    address_list next;
} ElmtList;
typedef struct
{
    address_list First;
} List;

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

boolean IsEmptyList(List L);
void CreateEmptyList(List *L);
address_list AlokasiList(infotypelist X);
void DealokasiList(address_list *P);
address_list SearchList(List L, infotypelist X);
void InsVFirst(List *L, infotypelist X);
void InsVLast(List *L, infotypelist X);
void DelVFirst(List *L, infotypelist *X);
void DelVLast(List *L, infotypelist *X);
void InsertFirst(List *L, address_list P);
void InsertAfter(List *L, address_list P, address_list Prec);
void InsertLast(List *L, address_list P);
void DelFirst(List *L, address_list *P);
void DelP(List *L, infotypelist X);
void DelLast(List *L, address_list *P);
void DelAfter(List *L, address_list *Pdel, address_list Prec);
void PrintInfo(List L);
int NbElmtList(List L);
infotypelist Max(List L);
address_list AdrMax(List L);
infotypelist Min(List L);
address_list AdrMin(List L);
float Average(List L);

#endif