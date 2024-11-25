#include <stdio.h>
#include "user.h"
// #include "....h" //pakai array item
#include "start.h"

void start(Item *arrItem, User *arrUser){
    printf("Membaca file konfigurasi...\n");
    load("default.txt", arrItem, arrUser);
    printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
}

void loading(){
    int i, j;

    printf("Entering PURRMART");
    for(i = 0; i < 10; i++) { 

        for(j = 0; j < 100000000; j++);
        printf("."); 

    }

    printf("<LOADING COMPLETE>\n\n");
}

void welcome(){
    
    printf("\n");
    printf("                                    W  E  L  C  O  M  E     T  O                                    \n");
    printf("     _ __                                               ___    ,---.                  ,--.--------. \n");
    printf("  .-`.' ,`.  .--.-. .-.-. .-.,.---.   .-.,.---.  .-._ .'=.'\ .--.'  \      .-.,.---. /==/,  -   , -\\n");
    printf(" /==/, -   \/==/ -|/=/  |/==/  `   \ /==/  `   \/==/ \|==|  |\==\-/\ \    /==/  `   \\==\.-.  - ,-./\n");
    printf("|==| _ .=. ||==| ,||=| -|==|-, .=., |==|-, .=., |==|,|  / - |/==/-|_\ |  |==|-, .=., |`--`\==\- \   \n");
    printf("|==| , '=',||==|- | =/  |==|   '='  /==|   '='  /==|  \/  , |\==\,   - \ |==|   '='  /     \==\_ \  \n");
    printf("|==|-  '..' |==|,  \/ - |==|- ,   .'|==|- ,   .'|==|- ,   _ |/==/ -   ,| |==|- ,   .'      |==|- |  \n");
    printf("|==|,  |    |==|-   ,   /==|_  . ,'.|==|_  . ,'.|==| _ /\   /==/-  /\ - \|==|_  . ,'.      |==|, |  \n");
    printf("/==/ - |    /==/ , _  .'/==/  /\ ,  )==/  /\ ,  )==/  / / , |==\ _.\=\.-'/==/  /\ ,  )     /==/ -/  \n");
    printf("`--`---'    `--`..---'  `--`-`--`--'`--`-`--`--'`--`./  `--` `--`        `--`-`--`--'      `--`--`  \n");

    printf("\n");
    printf("         ==================================================================================         \n");
    printf("             1. L O G I N   ||   2. R E G I S T E R   ||   3. H E L P   ||   4. Q U I T             \n");
    printf("         ==================================================================================         \n");
    printf("\n");
}