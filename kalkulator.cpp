#include <stdio.h>

void hitung(int *a, int *b, char op) {
    if (op == '+') {
        printf("Hasil: %d\n", *a + *b);
    } else if (op == '-') {
        printf("Hasil: %d\n", *a - *b);
    } else if (op == '*') {
        printf("Hasil: %d\n", (*a) * (*b));
    } else if (op == '/') {
        if (*b != 0) {
            printf("Hasil: %d\n", (*a) / (*b));
        } else {
            printf("Tidak bisa dibagi nol\n");
        }
    } else {
        printf("Operator tidak ada\n");
    }
}

int main() {
    int a, b;
    char op;

    printf("=== Kalkulator Pointer ===\n");
    printf("Masukkan angka pertama: ");
    scanf("%d", &a);
    printf("Masukkan operator (+, -, *, /): ");
    scanf(" %c", &op);
    printf("Masukkan angka kedua: ");
    scanf("%d", &b);

    hitung(&a, &b, op);

    return 0;
}