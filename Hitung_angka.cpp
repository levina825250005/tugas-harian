#include <stdio.h>

int main() {
    int i, n, jumlah = 0;

    printf("PROGRAM HITUNG JUMLAH ANGKA 1 - n\n\n");

    printf("Masukkan angka (n): ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        jumlah += i;
    }

    printf("Jumlah angka integer dari 1 sampai %d adalah %d\n", n, jumlah);

    return 0;
}