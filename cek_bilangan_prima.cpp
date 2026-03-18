#include <stdio.h>

void cekPrima(int *angka) {
    int i, Prima = 1;

    if (*angka <= 1) {
        Prima = 0;
    } else {
        for (i = 2; i <= *angka / 2; i++) {
            if (*angka % i == 0) {
                Prima = 0;
                break;
            }
        }
    }

    if (Prima)
        printf("%d adalah bilangan prima.\n", *angka);
    else
        printf("%d bukan bilangan prima.\n", *angka);
}

int main() {
    int angka;

    printf("Masukkan bilangan: ");
    scanf("%d", &angka);

    cekPrima(&angka);

    return 0;
}