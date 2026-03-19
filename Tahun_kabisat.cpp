#include <stdio.h>

int main() {
    int tahun;

    printf("Masukkan tahun: ");
    scanf("%d", &tahun);

    if(tahun % 4 == 0 && tahun % 100 != 0) {
        printf("Tahun kabisat\n");
    } else {
        if(tahun % 400 == 0) {
            printf("Tahun kabisat\n");
        } else {
            printf("Bukan tahun kabisat\n");
        }
    }

    return 0;
}