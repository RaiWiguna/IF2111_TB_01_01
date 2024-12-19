/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address_list dengan pointer */
/* infotypelist adalah string (nama barang) */

#ifndef listlinier_H
#define listlinier_H

#include "../mesinkata/mesinkata.h"
#include "../ArrayDinamis/ArrayDinamis.h"

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
} ListLinier;

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

boolean IsEmptyListLin(ListLinier L);
void CreateEmptyListLin(ListLinier *L);
address_list AlokasiListLin(infotypelist X);
void DealokasiListLin(address_list *P);
address_list SearchListLin(ListLinier L, infotypelist X);
address_list SearchListLinIdx (ListLinier L, int index);
void InsVFirstListLin(ListLinier *L, infotypelist X);
void InsVLastListLin(ListLinier *L, infotypelist X);
void DelVFirstListLin(ListLinier *L, infotypelist *X);
void DelVLastListLin(ListLinier *L, infotypelist *X);
void InsertFirstListLin(ListLinier *L, address_list P);
void InsertAfterListLin(ListLinier *L, address_list P, address_list Prec);
void InsertLastListLin(ListLinier *L, address_list P);
void DelFirstListLin(ListLinier *L, address_list *P);
void DelPListLin(ListLinier *L, infotypelist X);
void DelLastListLin(ListLinier *L, address_list *P);
void DelAfterListLin(ListLinier *L, address_list *Pdel, address_list Prec);
void PrintInfoListLin(ListLinier L);
// int NbElmtListLin(ListLinier L);
// infotypelist MaxListLin(ListLinier L);
// address_list AdrMaxListLin(ListLinier L);
// infotypelist MinListLin(ListLinier L);
// address_list AdrMinListLin(ListLinier L);
// float AverageListLin(ListLinier L);
void InversListListLin(ListLinier *L);
void Konkat1ListLin(ListLinier *L1, ListLinier *L2, ListLinier *L3);

boolean IsInListLin(ListLinier L,infotypelist X); 

#endif