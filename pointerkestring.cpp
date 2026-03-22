#include <stdio.h>

int main() {
    char *str = "Nama saya Levina";

    printf("String: %s\n", str);

    while (*str != '\0') {
        printf("%c ", *str);
        str++;
    }

    return 0;
}