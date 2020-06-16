#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ptrace.h>

int auth(char *str, unsigned int s) {
    int length;
    int t;
    int j;
    int i;
    int i2;
    int i3;
    int i4;

    str[strcspn(str, "\n")] = "\0";
    length = strnlen(str, 32);
    if (length <= 5)
        return (1);
    t = ptrace(0, 0, 1, 0);
    if (t == -1) {
        puts("\033[32m.---------------------------."); // 27 -
        puts("\033[31m| !! TAMPERING DETECTED !!  |");
        puts("\033[32m.---------------------------."); // 27 -
        return 1;
    }
    i = str[3] ^ 4919 + 6221293;
    j = -1;
    while (++j < length) {
        if (str[i] <= 0x1f)
            return (1)
        i2 = str[i] ^ i;
        i3 = (int)((int64_t)0x88233b2b * i2 / 0x100000000);
        i4 = i2 * ((i2 - i3) / 2 + i3) / 1024 * (-1337) + i;
        i = i4;
    }
    if (i == s)
        return 0;
    return 1;
}

int main() {

    char str[32];
    unsigned int s;

    puts("***********************************"); // 35 *
    puts("*\t\tlevel06\t\t  *");
    puts("***********************************"); // 35 *
    printf("-> Enter Login: ");
    fgets(str, 32, stdin);
    puts("***********************************"); // 35 *
    puts("***** NEW ACCOUNT DETECTED ********");
    puts("***********************************"); // 35 *
    printf("-> Enter Serial: ");
    scanf("%u", &s);
    if (auth(str, s) == 0) {
        puts("Authenticated!");
        system("/bin/sh");
    }
    return 0;
}