#include "menu.h"

void Welcomemenu(){
    printf("     |  __ \\\                                    | |  \n");
    printf("     | |__) |   _ _ __ _ __ _ __ ___   __ _ _ __| |_ \n");
    printf("     |  ___/ | | | '__| '__| '_ ` _ \\\ / _` | '__| __|\n");
    printf("     | |   | |_| | |  | |  | | | | | | (_| | |  | |_ \n");
    printf("     |_|    \\\__,_|_|  |_|  |_| |_| |_|\\\__,_|_|   \\\__|\n");

    time_t start_time = time(NULL);
    while (difftime(time(NULL), start_time) < 3) {
    }
    system("cls");

    printf("     _             _\n");
    printf(" ___| |_ __ _ _ __| |_\n");
    printf("/ __| __/ _` | '__| __|\n");
    printf("\\\__ \\\ || (_| | |  | |_ \n");
    printf("|___/\\\__\\\__,_|_|   \\\__|\n");

    printf("\n");

    printf(" _                 _ \n");
    printf("| | ___   __ _  __| |\n");
    printf("| |/ _ \\\ / _` |/ _` |\n");
    printf("| | (_) | (_| | (_| |\n");
    printf("|_|\\\___/ \\\__,_|\\\__,_|\n");

    printf("\n"); 

    printf(" _          _       \n");
    printf("| |__   ___| |_ __\n");
    printf("| '_ \\\ / _ \\\ | '_ \\\n");
    printf("| | | |  __/ | |_) |\n");
    printf("|_| |_|\\\___|_| .__/ \n");
    printf("             |_| \n");
}