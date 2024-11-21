#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "menu.h"
#include "ADT\mesinkata\mesinkata.h"

int main(){
    Word Input ;
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");  // Untuk Windows
    #else
        system("clear");  // Untuk Linux/Mac
    #endif
    Welcomemenu();
    STARTWORD();
    Input = CurrentWord;
}