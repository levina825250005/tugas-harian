#include <stdio.h>

int main() {
    int n, hitung = 0;

    printf("Masukkan angka: ");
    scanf("%d", &n);

    while(n != 0) {
        n = n / 10;
        hitung++;
    }

    printf("Jumlah digit: %d\n", hitung);

    return 0;
}