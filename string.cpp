#include <stdio.h>
#include <string.h>

int main() {
    char kata[100];
    int i, panjang;

    printf("Masukkan kata: ");
    scanf("%s", kata);

    panjang = strlen(kata);

    printf("Hasil dibalik: ");
    for(i = panjang - 1; i >= 0; i--) {
        printf("%c", kata[i]);
    }

    printf("\n");
    return 0;
}