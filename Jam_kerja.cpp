#include <stdio.h>

int main() {
    char gol;
    int jamKerja;
    int a, b, c;

    printf("Masukkan golongan (A/B/C): ");
    scanf(" %c", &gol);

    printf("Masukkan jam kerja: ");
    scanf("%d", &jamKerja);

    a = 10000 * jamKerja;
    b = 7500 * jamKerja;
    c = 5000 * jamKerja;

    if (gol == 'A') {
        printf("Gaji: %d\n", a);
    } else if (gol == 'B') {
        printf("Gaji: %d\n", b);
    } else if (gol == 'C') {
        printf("Gaji: %d\n", c);
    } else {
        printf("Golongan tidak valid\n");
    }

    return 0;
}