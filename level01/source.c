#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int verify_user_name(char *name) {
    int test_name;

    puts("verifying username....\n");
    test_name = strncmp(name, "dat_wil", 7);
    return test_name;
}

int verify_user_pass(char *pass) {
    int test_pass;

    test_pass = strncmp(pass, "admin", 5);
    return test_pass;
}

int main () {
    int verify_name;
    int verify_pass;
    char name[100];
    char pass[80];

    puts("********* ADMIN LOGIN PROMPT *********");
    printf("Enter Username:");
    fgets(name, 256, stdin);
    verify_name = verify_user_name(name);
    if (verify_name != 0) {
        puts("nope, incorrect username...\n");
        return 0;
    }
    puts("Enter Password\n");
    fgets(pass, 100, stdin);
    verify_pass = verify_user_pass(pass);
    if (verify_pass || !verify_pass) {
        puts("nope, incorrect password...\n");
        return 0;
    }
    return 0;
}