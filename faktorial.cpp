#include <stdio.h>

int main() {
    int i, n;
    int hasil = 1;

    printf("Masukkan angka: ");
    scanf("%d", &n);

        for (i = 1; i <= n; i++) {
            hasil = hasil * i;
        }

        printf("Faktorial dari %d = %d\n", n, hasil);

    return 0;
}