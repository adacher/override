#include <stdio.h>          
#include <stdlib.h>
#include <time.h>

void decrypt (int n) {
    char str[] = "Q}|u`sfgrsf{}|a3";
    int i;
    
    i = -1;
    while (++i < strlen(str))
        str[i] = n ^ str[i]
    if (strncmp(str, "Congratulations!", 17) == 0) {
        system("/bin/sh");
    } else {
        puts("\nInvalid Password");
    }
}

void test(int n) {
    switch (n) {
        
        case 1:
            decrypt(1);
            break;

        case 2:
            decrypt(2);
            break;

        case 3:
            decrypt(3);
            break;

        case 4:
            decrypt(4);
            break;

        case 5:
            decrypt(5);
            break;

        case 6:
            decrypt(6);
            break;

        case 7:
            decrypt(7);
            break;

        case 8:
            decrypt(8);
            break;
        
        case 9:
            decrypt(9);
            break;

        case 10:
            decrypt(10);
            break;

        case 11:
            decrypt(11);
            break;

        case 12:
            decrypt(12);
            break;

        case 13:
            decrypt(13);
            break;

        case 14:
            decrypt(14);
            break;

        case 15:
            decrypt(15);
            break;

        case 16:
            decrypt(16);
            break;
        
        case 17:
            decrypt(17);
            break;

        case 18:
            decrypt(18);
            break;

        case 19:
            decrypt(19);
            break;

        case 20:
            decrypt(20);
            break;

        case 21:
            decrypt(21);
            break;

        default:
            decrypt(rand());
            break;

    }
}

int main() {
    int scan;
    
    srand(time(NULL));
    puts("***********************************"); // 35 *
    puts("*\t\tlevel03\t\t**");
    puts("***********************************"); // 35 *
    printf("Password:");
    scanf("%d", &scan);
    test(scan - 322424845);
    return 0;
}