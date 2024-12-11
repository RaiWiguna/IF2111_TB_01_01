#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "console.h"

void clearTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main(){
    // Kamus Lokal
    User u;
    ArrayDin Item;
    TabInt T;
    Queue Q;
    boolean status = false;
    boolean login =false;
    boolean loginActive = false;
    int currentUserIndex = -1;
    MakeList(&T);
    MakeArrayDin(&Item);

    // Algoritma
    clearTerminal();

    int menuState = 1, tes=0;
    
    while (1)
    {
        if(menuState == 1) {

            printf("\nMasukkan command: ");
            STARTWORD();

            if (IsSame(CurrentWord.TabWord, "start"))
            {
                Start(login);
                menuState = 2;
            }
            else if (IsSame(CurrentWord.TabWord, "load"))
            {
                Load(&Item, &login);
            }
            else if(IsSame(CurrentWord.TabWord, "quit"))
            {
                QUIT(&status, T);
                break;
            }
            else if (IsSame(CurrentWord.TabWord, "help"))
            {
                clearTerminal();
                Help(menuState);
            } 
            else {
                printf("Command tidak valid\n");
            }
        } 
        else if (menuState == 2)
        {
            printf("\nMasukkan command: ");
            STARTWORD();

            if (IsSame(CurrentWord.TabWord, "register"))
            {
                Register();
            }
            else if (IsSame(CurrentWord.TabWord, "login"))
            {
                Login(currentUserIndex, &loginActive);
                if (loginActive) 
                {
                    menuState = 3; 
                    Help(menuState);
                }
            } 
            else if(IsSame(CurrentWord.TabWord, "quit"))
            {
                QUIT(&status, T);
                break;
            }
            else if (IsSame(CurrentWord.TabWord, "help"))
            {
                clearTerminal();
                Help(menuState);
            } 
            else {
                printf("Command tidak valid\n");
            }

        } 
        else if (menuState == 3)
        {
            printf("\nMasukkan command: ");
            STARTWORD();

            if (IsSame(CurrentWord.TabWord, "work"))
            {
                Work(&u);
            } 
            else if (IsSame(CurrentWord.TabWord, "work challenge"))
            {
                workChallenge(&u);
            } 
            else if(IsSame(CurrentWord.TabWord, "store list"))
            {
                storeList(Item);
            } 
            else if (IsSame(CurrentWord.TabWord, "store request"))
            {
                storeRequest(&Q, Item);
            } 
            else if (IsSame(CurrentWord.TabWord, "store supply"))
            {
                storeSupply(Q, &Item);
            } 
            else if (IsSame(CurrentWord.TabWord, "store remove"))
            {
                storeRemove(&Item);
            } 
            else if (IsSame(CurrentWord.TabWord, "logout"))
            {
                Logout(currentUserIndex);
                menuState = 2;
            } 
            else if (IsSame(CurrentWord.TabWord, "save")) {
                printf("Masukkan nama file untuk menyimpan data: ");
                string filename;
                STARTWORD();
                filename = CurrentWord.TabWord;
                SAVE(filename, T);
            }
            else if (IsSame(CurrentWord.TabWord, "quit"))
            {
                QUIT(&status, T);
                break;
            } 
            else if (IsSame(CurrentWord.TabWord, "help"))
            {
                clearTerminal();
                Help(menuState);
            } 
            else {
                printf("Command tidak valid\n");
            }

        }
    }
}
