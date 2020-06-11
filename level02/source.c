int main () {
    FILE *file;
    char messageError[] = "ERROR: failed to open password file\n";
    char userName[100];
    char password[100];
    char buffer[42];
    int n;
    int n2;
    int n3;

    file = fopen("/home/user/level03/.pass", "r");
    if (!file) {
        fwrite(messageError, 1, sizeof(messageError), stderr);
        exit(1);
    }
    fread(buffer, 1, 41, file);
    n = strcspn(buffer, "\n");
    if (41 == strlen(buffer)) {
        fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
        fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
        exit(1);
    }
    fclose(file);
    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/****************************************\\"); // 39 *
    puts("| You must login to access this system. |");
    puts("\\**************************************/"); // 38 *
    printf("--[ Username: ");
    fgets(userName, 100, stdin);
    n2 = strcspn(userName, "\n");
    printf("--[ Password: ");
    fgets(password, 100, stdin)
    n3 = strcspn(password, "\n");
    puts("******************************************"); // 41 *
    if (strncmp(password, buffer) == 0) {
        printf("Greetings, %s!\n");
        system("/bin/sh");
        return (0);
    }
    printf(userName);
    puts(" does not have access!");
    exit(1);
}