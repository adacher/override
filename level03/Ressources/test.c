#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int i;
    char str[] = "Q}|u`sfg~sf{}|a3";
    char *secondStr;
    int j;
    int nb;

    i = 0;
    while (++i < 22) {
        secondStr = malloc(20);
        j = -1;
        while (++j < strlen(str)) {
            secondStr[j] = i ^ str[j];
        }
        secondStr[j] = '\0';
        printf("%s, %d\n", secondStr, i);
    }
    return 0;
}