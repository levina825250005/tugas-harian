#include <stdio.h>

int main() {
    int i, n, angka;

    printf("Berapa banyak angka yang ingin dicek: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Masukkan angka ke-%d: ", i);
        scanf("%d", &angka);

        if (angka % 2 == 0) {
            printf("%d adalah bilangan genap.\n", angka);
        } else {
            printf("%d adalah bilangan ganjil.\n", angka);
        }
    }

    return 0;
}