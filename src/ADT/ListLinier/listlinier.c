#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsEmptyListLin(ListLinier L) {
    return (First(L) == NilList);
}

void CreateEmptyListLin(ListLinier *L) {
    First(*L) = NilList;
}

address_list AlokasiListLin(infotypelist X) {
    address_list P = (address_list)malloc(sizeof(ElmtList));
    if (P != NilList) {
        Info(P) = (char*)malloc((strLength(X) + 1) * sizeof(char));
        copyString(Info(P), X);
        Next(P) = NilList;
    }
    return P;
}

void DealokasiListLin(address_list *P) {
    free(Info(*P));
    free(*P);
    *P = NilList;
}

address_list SearchListLin(ListLinier L, infotypelist X) {
    address_list P = First(L);
    while (P != NilList) {
        if (IsSame(Info(P), X) == 0) {
            return P;
        }
        P = Next(P);
    }
    return NilList;
}

void InsVFirstListLin(ListLinier *L, infotypelist X) {
    address_list P = AlokasiListLin(X);
    if (P != NilList) {
        InsertFirstListLin(L, P);
    }
}

void InsVLastListLin(ListLinier *L, infotypelist X) {
    address_list P = AlokasiListLin(X);
    if (P != NilList) {
        InsertLastListLin(L, P);
    }
}

void DelVFirstListLin(ListLinier *L, infotypelist *X) {
    address_list P;
    DelFirstListLin(L, &P);
    *X = Info(P);
    DealokasiListLin(&P);
}

void DelVLastListLin(ListLinier *L, infotypelist *X) {
    address_list P;
    DelLastListLin(L, &P);
    *X = Info(P);
    DealokasiListLin(&P);
}

void InsertFirstListLin(ListLinier *L, address_list P) {
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfterListLin(ListLinier *L, address_list P, address_list Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLastListLin(ListLinier *L, address_list P) {
    if (IsEmptyListLin(*L)) {
        InsertFirstListLin(L, P);
    } else {
        address_list Last = First(*L);
        while (Next(Last) != NilList) {
            Last = Next(Last);
        }
        Next(Last) = P;
    }
}

void DelFirstListLin(ListLinier *L, address_list *P) {
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = NilList;
}

void DelPListLin(ListLinier *L, infotypelist X) {
    address_list P = First(*L);
    if (IsSame(Info(P), X) == 0) {
        DelFirstListLin(L, &P);
        DealokasiListLin(&P);
    } else {
        address_list Prec = NilList;
        while (P != NilList && IsSame(Info(P), X) != 0) {
            Prec = P;
            P = Next(P);
        }
        if (P != NilList) {
            DelAfterListLin(L, &P, Prec);
            DealokasiListLin(&P);
        }
    }
}

void DelLastListLin(ListLinier *L, address_list *P) {
    if (Next(First(*L)) == NilList) {
        DelFirstListLin(L, P);
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

void DelAfterListLin(ListLinier *L, address_list *Pdel, address_list Prec) {
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = NilList;
}

void PrintInfoListLin(ListLinier L) {
    address_list P = First(L);
    int id=1;
    printf("Berikut adalah isi wishlist: \n");
    while (P != NilList) {
        printf("%d. %s\n", id,Info(P));
        id++;
        P = Next(P);
    }
}

int NbElmtListListLin(ListLinier L) {
    int count = 0;
    address_list P = First(L);
    while (P != NilList) {
        count++;
        P = Next(P);
    }
    return count;
}

// infotypelist MaxListLin(ListLinier L) {
//     address_list P = First(L);
//     infotypelist max = Info(P);
//     while (P != NilList) {
//         if (strcompare(Info(P), max) > 0) {
//             max = Info(P);
//         }
//         P = Next(P);
//     }
//     return max;
// }

// address_list AdrMaxListLin(ListLinier L) {
//     address_list P = First(L);
//     address_list maxAdr = P;
//     infotypelist max = Info(P);
//     while (P != NilList) {
//         if (strcompare(Info(P), max) > 0) {
//             max = Info(P);
//             maxAdr = P;
//         }
//         P = Next(P);
//     }
//     return maxAdr;
// }

// infotypelist MinListLin(ListLinier L) {
//     address_list P = First(L);
//     infotypelist min = Info(P);
//     while (P != NilList) {
//         if (strcompare(Info(P), min) < 0) {
//             min = Info(P);
//         }
//         P = Next(P);
//     }
//     return min;
// }

// address_list AdrMinListLin(ListLinier L) {
//     address_list P = First(L);
//     address_list minAdr = P;
//     infotypelist min = Info(P);
//     while (P != NilList) {
//         if (strcompare(Info(P), min) < 0) {
//             min = Info(P);
//             minAdr = P;
//         }
//         P = Next(P);
//     }
//     return minAdr;
// }

// float AverageListLin(ListLinier L) {
//     int sum = 0;
//     int count = 0;
//     address_list P = First(L);
//     while (P != NilList) {
//         sum += atoi(Info(P)); // Assuming Info(P) contains numeric strings
//         count++;
//         P = Next(P);
//     }
//     return (float)sum / count;
// }

void InversListListLin(ListLinier *L) {
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

void Konkat1ListLin(ListLinier *L1, ListLinier *L2, ListLinier *L3) {
    address_list Last1;
    CreateEmptyListLin(L3);
    if (IsEmptyListLin(*L1)) {
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