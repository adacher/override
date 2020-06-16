#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct forum {
    char message[140];
    char username[40];
    int messageLength;
} forum;

void secret_backdoor() {
    char buffer[128];

    fgets(buffer, 128, stdin);
    system(buffer);
}

void set_username(forum *forum) {
    char buffer[128];
    char username[40];
    int i;

    puts(">: Enter your username");
    printf(">>: ");
    fgets(buffer, 128, stdin);
    i = -1;
    while (++i <= 40 && buffer[i]) {
        forum->username[i] = buffer[i];
    }
    printf(">: Welcome, %s", forum->username)
}

void set_msg(forum *forum) {
    char buffer[1024];
    
    puts(">: Msg @Unix-Dude");
    printf(">>: ");
    fgets(buffer, 1024, stdin);
    strncpy(forum->message, buffer, forum->messageLength);
}


void handle_msg() {
    forum forum;

    forum.messageLength = 140;
    set_username(&forum);
    set_msg(&forum);
    puts(">: Msg sent!");
}

int main() {
    puts("
        --------------------------------------------\n
        |   ~Welcome to l33t-m$n ~    v1337        |\n
        --------------------------------------------\n
    ");
    handle_msg();
    return 0;
}