#include <stdio.h>

int main() {
    int nilai, hadir;

    printf("Masukkan nilai: ");
    scanf("%d", &nilai);
    printf("Masukkan kehadiran: ");
    scanf("%d", &hadir);

    if(nilai >= 75) {
        printf("Lulus\n");
    } else {
        if(hadir <= 3) {
            printf("Lulus\n");
        } else {
            printf("Tidak lulus\n");
        }
    }

    return 0;
}