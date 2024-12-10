#ifndef map_H
#define map_H

#include "boolean.h"
#include "mesinkata.h"

#define NilMap 0
#define MaxElMap 205
#define Undefined 0

typedef char* keytype; // Nama barang
typedef int valuetype; // Kuantitas barang
typedef int address_map;

typedef struct {
    keytype Key;
    valuetype Value;
} infotype;

typedef struct {
    infotype Elements[MaxElMap];
    address_map Count;
} Map;

#define Count(M) (M).Count
#define Elements(M) (M).Elements

boolean IsEmptyMap(Map M);
void CreateEmptyMap(Map *M);
void InsertMap(Map *M, keytype k, valuetype v);
void DeleteMap(Map *M, keytype k);
boolean IsMemberMap(Map M, keytype k);
int idxMap(Map M, keytype k);

#endif