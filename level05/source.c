int main() {
    int i;
    char str[32];

    i = -1;
    fgets(str, 32, stdin);
    while (++i < strlen(str))
        if (str[i] > '@' && str[i] <= 'z')
            str[i] += 32;
    printf(str);
    return 0;
}