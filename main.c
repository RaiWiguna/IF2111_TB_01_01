#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "menu.h"
#include "mesinkata.h"

int main(){
    Word Input;
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");  // Untuk Windows
    #else
        system("clear");  // Untuk Linux/Mac
    #endif
    Welcomemenu();

    char pilihanmenu[100];
    int menuState = 1, tes=0;
    scanf("%s", pilihanmenu);
    
    while (1)
    {
        if(menuState == 1) {
            printf("Masukkan command: ");
            char pilihanmenu[100];
            STARTWORD();
            if (pilihanmenu == "start")
            {
                //start();
                tes++;
            } else if (pilihanmenu == "load")
            {
                tes++;
                // load();
            } else if(pilihanmenu == "quit") {
                // help();
                tes++;
            } else if (pilihanmenu == "help")
            {
                // quit();
                tes++;
            } else {
                printf("Command tidak valid\n");
            }

        } else if (menuState == 2)
        {
            if (pilihanmenu == "register")
            {
                //start();
                tes++;
            } else if (pilihanmenu == "login")
            {
                tes++;
            // load();
            } else if(pilihanmenu == "quit") {
                // help();
                tes++;
            } else if (pilihanmenu == "help")
            {
                // quit();
                tes++;
            } else {
                printf("Command tidak valid\n");
            }

        } else if (menuState == 3)
        {
            if (pilihanmenu == "work")
            {
                //start();
                tes++;
            } else if (pilihanmenu == "work challenge")
            {
                tes++;
            // load();
            } else if(pilihanmenu == "store list") {
                // help();
                tes++;
            } else if (pilihanmenu == "store request")
            {
                // quit();
                tes++;
            } else if (pilihanmenu == "store supply")
            {
                // quit();
                tes++;
            } else if (pilihanmenu == "store remove")
            {
                // quit();
                tes++;
            } else if (pilihanmenu == "logout")
            {
                // quit();
                tes++;
            } else if (pilihanmenu == "save")
            {
                // quit();
                tes++;
            } else if (pilihanmenu == "quit")
            {
                // quit();
                tes++;
            } else if (pilihanmenu == "help")
            {
                // quit();
                tes++;
            } else {
                printf("Command tidak valid\n");
            }

        }
        
        
    }
}

void start() {

}





/*
int main(){
    ArrayDin Item;
    ReadFile("../../../save/ListBarang.txt",&Item);
    storeList(Item);
}
*/