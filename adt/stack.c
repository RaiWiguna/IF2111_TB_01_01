#include "stack.h"

boolean IsEmptyStack(Stack S) {
    return (Top(S) == NilStack);
}

void CreateEmptyStack(Stack *S) {
    Top(*S) = NilStack;
    S->totalBiaya = 0;
}

void PushStack(Stack *S, infotypeStack X) {
    if (IsEmptyStack(*S)) {
        Top(*S) = 0;
    } else {
        Top(*S)++;
    }
    InfoTop(*S) = X;
    S->totalBiaya += X.totalHarga;
}

void PopStack(Stack *S, infotypeStack *X) {
    *X = InfoTop(*S);
    S->totalBiaya -= X->totalHarga;
    Top(*S)--;
}