#include "mesinkarakter.h"

char CC;
int EOP;

void START() {
    CC = getchar();
    EOP = (CC == MARK);
}

void ADV() {
    CC = getchar();
    EOP = (CC == MARK);
}

char GetCC(){
    return CC;
}