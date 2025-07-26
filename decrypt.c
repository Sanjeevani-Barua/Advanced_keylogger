#include <stdio.h>

#define XOR_KEY 'K'

int main() {
    FILE *file = fopen("log.txt", "r");
    char ch;
    if (!file) return 1;

    while ((ch = fgetc(file)) != EOF) {
        ch ^= XOR_KEY;
        putchar(ch);
    }

    fclose(file);
    return 0;
}
