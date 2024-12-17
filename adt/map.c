#include "map.h"
#include <stdio.h>
#include <stdlib.h>


boolean IsEmptyMap(Map M) {
    return (Count(M) == NilMap);
}

void CreateEmptyMap(Map *M) {
    Count(*M) = NilMap;
}

void InsertMap(Map *M, keytype k, valuetype v) {
    if (M->Count < MaxElMap) {
        M->Elements[M->Count].Key = (char*)malloc((strlength(k) + 1) * sizeof(char));
        if (M->Elements[M->Count].Key == NULL) {
            printf("Gagal mengalokasikan memori untuk Key\n");
            return;
        }
        strcopy(M->Elements[M->Count].Key, k);
        M->Elements[M->Count].Value = v;
        M->Count++;
    }
}

void DeleteMap(Map *M, keytype k) {
    address_map idx = 0;
    while (idx < Count(*M) && !isKataEqual(Elements(*M)[idx].Key, k)) {
        idx++;
    }
    if (idx < Count(*M)) {
        for (address_map i = idx; i < Count(*M) - 1; i++) {
            Elements(*M)[i] = Elements(*M)[i + 1];
        }
        Count(*M)--;
    }
}

boolean IsMemberMap(Map M, keytype k) {
    for (int i = 0; i < M.Count; i++) {
        if (isKataEqual(M.Elements[i].Key, k)) {
            return true;
        }
    }
    return false;
}

int idxMap(Map M, keytype k) {
    address_map idx = 0;
    while (idx < Count(M)) {
        if (isKataEqual(Elements(M)[idx].Key, k)) {
            return idx;
        }
        idx++;
    }
    return -1;
}