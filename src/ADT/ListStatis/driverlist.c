#include <stdio.h>
#include "listlinear.h"

int main(){
    List l1;
    MakeList(l1);
    printf("%d IsEmpty",IsEmpty(l1));
    return 0;
}