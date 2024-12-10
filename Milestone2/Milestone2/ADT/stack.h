#ifndef stack_H
#define stack_H

#include "boolean.h"
#include "mesinkata.h"

#define NilStack -1
#define MaxElStack 100

typedef struct {
    char* namaBarang;
    int totalHarga;
} infotypeStack;

typedef int address_stack;

typedef struct {
    infotypeStack T[MaxElStack];
    address_stack TOP;
    int totalBiaya;
} Stack;

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

boolean IsEmptyStack(Stack S);
void CreateEmptyStack(Stack *S);
void PushStack(Stack *S, infotypeStack X);
void PopStack(Stack *S, infotypeStack *X);

#endif