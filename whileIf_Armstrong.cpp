#include <stdio.h>

int main() {
    int n, temp, digit, sum = 0;
    printf("Masukkan angka: ");
    scanf("%d", &n);
    temp = n;

    while (temp != 0) {
        digit = temp % 10;
        int cube = 1;
        for (int i = 0; i < 3; i++) cube *= digit;
        sum += cube;
        temp /= 10;
    }

    if (sum == n)
        printf("%d adalah bilangan Armstrong\n", n);
    else
        printf("%d bukan bilangan Armstrong\n", n);
    return 0;
}