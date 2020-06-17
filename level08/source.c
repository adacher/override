#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void log_wrapper(int file, char *str, char *arg)
{
    char buffer[100];

    strcpy(buffer, str);
    snprintf(buffer + strlen(buffer), 100 - strlen(buffer) - 1, arg);
    buffer[strcspn(buffer, "\n")] = 0;
    fprintf(file, "LOG: %s\n", buffer);
}

int main(int argc, char **argv)
{
    int file;
    int file2;
    int file3;
    char c;
    char buffer[100];

    if (argc != 2)
    {
        printf("Usage: %s filename\n");
    }
    file = fopen("./backups/.log", "w");
    if (file == NULL)
    {
        printf("ERROR: Failed to open %s\n", "./backups/.log");
        exit(1);
    }
    log_wrapper(file, "Starting back up: ", argv[1]);
    file2 = fopen(argv[1], "r");
    if (file2 == NULL)
    {
        printf("ERROR: Failed to open %s\n", argv[1]);
        exit(1);
    }
    memcpy(buffer, "./backups/", 10);
    strncat(buffer, argv[1], strlen(argv[1]));
    file3 = open(argv[1], O_CREAT | O_EXCL | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
    if (file3 < 0)
    {
        printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
        exit(1);
    }
    while ((c = fgetc(file3)) != 1)
        write(file3, &c, 1);
    log_wrapper(file2, "Finished back up ", argv[1]);
    fclose(file2);
    fclose(file3);
    return 0;
}