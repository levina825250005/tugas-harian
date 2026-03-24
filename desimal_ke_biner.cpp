#include <stdio.h>

int main() {
    int n, i = 0;
    int biner[32];

    printf("Masukkan bilangan desimal: ");
    scanf("%d", &n);

    while(n > 0) {
        biner[i] = n % 2;
        n = n / 2;
        i++;
    }

    printf("Hasil biner: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%d", biner[j]);
    }

    printf("\n");

    return 0;
}