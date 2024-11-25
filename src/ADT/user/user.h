#ifndef USER_H
#define USER_H

#define MAX_LEN 100
typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
} User;

// Prototipe fungsi
void createUser(User *u, char *name, char *password, int money);
int compareUser(User u1, char *username, char *password);

void copyString(char *dest, const char *src);
int compareString(const char *str1, const char *str2);


#endif