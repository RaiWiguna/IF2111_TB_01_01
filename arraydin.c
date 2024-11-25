#include "arraydin.h"

void DeleteAt(arraydin *array, IdxType i) {
    for (int j = i; j < array->Neff - 1; j++) {
        array->Isi[j] = array->Isi[j + 1];
    }
    array->Neff--;
}