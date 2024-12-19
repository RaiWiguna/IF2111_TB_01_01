#include <stdio.h>
#include <stdlib.h>

#include "liststatis.h"

// Konstruktor
List MakeList() {
	// Kamus lokal
	List L;
	// Algoritma
	L.Neff=0;
	return L;
}

// Processing
boolean IsEmptyList(List L) {
	return (L.Neff == 0);
}

int Length(List L) {
	return(L.Neff);
}


// ElType GetUser(List L, IdxType i) {
// 	return (L.Account[i].name);
// }

// ElType GetPassword(List L, IdxType i) {
// 	return (L.Account[i].password);
// }

void Set(List *L, IdxType i, string Acc, string Pass,string money) {
	copyString((*L).Account[i].name,Acc);
	copyString((*L).Account[i].password,Pass);
	(*L).Account[i].money = atoi(money);
}

void CetakList(List L){
	// Kamus Lokal 
	int length = Length(L);

	// Algoritma
	for (int i =0;i<length;i++){
		printf("%d %s %s\n",L.Account[i].money,L.Account[i].name,L.Account[i].password);
	}
}
IdxType FirstIdx(List L) {
    return 0;
}

IdxType LastIdx(List L) {
	int i = FirstIdx(L);
	while ((i < MaxEl) && (L.Neff != Mark)) {
		i += 1;
	}
	return i;
}

boolean IsIdxValid (List L, IdxType i) {
	return (0 <= i) && (MaxEl >= i);
}

boolean IsIdxEff (List L, IdxType i) {
	return (FirstIdx(L) <= i) && (LastIdx(L) >= i);
}

// boolean Search(List L, ElType X) {
// 	int i = FirstIdx(L);
// 	int j = LastIdx(L);
// 	boolean found = false;
// 	while ((i <= j) && !found) {
// 		i += 1;
// 		if (L.A[i] == X) {
// 			found = true;
// 		}
// 	}
//     return found;
// }

// void InsertFirst(List *L, ElType X) {
// 	IdxType i = LastIdx(*L);
// 	IdxType j = FirstIdx(*L);
// 	while (i > j) {
// 		Set(L, i+1, Get(*L, i));
// 		i--;
// 	}
// 	Set(L, j, X);
// }

// void InsertAt(List *L, ElType X, IdxType i) {
//     IdxType j = LastIdx(*L);
// 	while (i <= j) {
// 		Set(L, j+1, Get(*L, j));
//         j--;
// 	}
// 	Set(L, i, X);
// }

void InsertLastList(List *L, string Acc, string Pass,string Money ) {
    // Kamus Lokal
	int last = Length(*L);

	// Algoritma
	copyString((*L).Account[last].name,Acc);
	copyString((*L).Account[last].password,Pass);
	(*L).Account[last].money = atoi(Money);

	(*L).Neff++;
}

// void DeleteFirst(List *L) {
// 	int i = FirstIdx(*L);
// 	while (i < LastIdx(*L)) {
// 		(*L).A[i] = (*L).A[i+1];
//         i++;
// 	}
//     (*L).A[i] = Mark;
// }

// void DeleteAt(List *L, IdxType i) {
// 	int j = LastIdx(*L);
// 	// while (i <= j) {
// 	// 	(*L).A[j] = (*L).A[j+1];
//     //     j--;
// 	// }
// 	while (i <= j) {
// 		(*L).A[i] = (*L).A[i+1];
//         i++;
// 	}
// }

// void DeleteLast(List *L) {
// 	(*L).A[LastIdx(*L)] = Mark;
// }