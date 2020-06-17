#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_unum()
{
    unsigned int i;

    i = 0;
    fflush(stdout);
    scanf("%u", &i);
    clear_stdin();
    return i;
}

void clear_stdin()
{
    char a;

    a = 0;
    while (a != 0xa && a != 0xff)
        a = getchar();
}

int read_number(unsigned int *dataStore)
{
    unsigned int i;

    printf(" Index: ");
    i = get_unum();
    printf(" Number at data[%u] is %u\n", i);
    return i;
}

int store_number(unsigned int *dataStore)
{
    unsigned int i; // 0x10
    unsigned int j; // 0xc

    printf(" Number: ");
    i = get_unum();
    printf(" Index: ");
    j = get_unum();
    if ((i % 3 == 0) || 0xb7 == (i >> 24))
    {
        puts(" *** ERROR! ***");
        puts("   This index is reserved for wil!");
        puts(" *** ERROR! ***");
        return 1;
    }
    dataStore[j] = i;
    return 0;
}

int main(int argc, char **argv, char **cenvs)
{
    char buffer[20];
    unsigned int dataStore[100] = {0}; // rep stoz 0x64 0x0
    int res;                           // 0x1b4
    char **args = argv;
    char **envs = cenvs;
    int i;

    i = 0;
    while (argv[i])
    {
        memset(argv[i], 0, strlen(argv[i]));
        i++;
    }
    i = 0;
    while (envs[i])
    {
        memset(envs[i], 0, strlen(envs[i]));
        i++;
    }
    puts("
        ----------------------------------------------------\n
          Welcome to wil's crappy number storage service!\n
        ----------------------------------------------------\n
         Commands:\n
            store - store a number into the data storage\n
            read  - read a number from the data storage\n
            quit  - exit the program\n
        ----------------------------------------------------\n
           wil has reserved some storage :>\n
        ----------------------------------------------------\n
    ");
    while (1) {
        res = 1;
        printf("Input command: ");
        fgets(buffer, 20, stdin);
        if (strncmp(buffer, "store", 5) == 0)
            res = store_number(dataStore);
        else if (strncmp(buffer, "read", 4) == 0)
            res = read_number(dataStore);
        else if (strncmp(buffer, "quit", 4) == 0)
            return 0;
        if (res == 0)
            printf(" Failed to do %s command\n", buffer);
        else
            printf(" Completed %s command successfully\n", buffer);
    }
    return 0;
}