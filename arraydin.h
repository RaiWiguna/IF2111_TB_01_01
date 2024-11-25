#ifndef ARRAY_DINAMIK
#define ARRAY_DINAMIK

#include "adtkustom.h"
#include "boolean.h"

typedef int IdxType;
typedef struct {
    Barang *Isi;
    int Capacity;
    int Neff;
} arraydin;

void DeleteAt(arraydin *array, IdxType i);

#endif