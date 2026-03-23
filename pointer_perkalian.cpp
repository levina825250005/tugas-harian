#include <stdio.h>

int main() {
    int a, b;
    int *p = &a, *q = &b;

    printf("Masukkan Nilai a = ");
    scanf("%d", &a);

    printf("Masukkan Nilai b = ");
    scanf("%d", &b);

    int hasil = *p * *q;

    printf("Hasil = %d\n", hasil);

    return 0;
}