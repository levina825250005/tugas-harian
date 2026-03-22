#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a, b;

    printf("Masukkan Nilai a = ");
    scanf("%d", &a);

    printf("Masukkan Nilai b = ");
    scanf("%d", &b);

    printf("Sebelum swap: a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("Sesudah swap: a=%d, b=%d\n", a, b);

    return 0;
}