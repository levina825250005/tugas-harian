#include <stdio.h>

float keFahrenheit(float c) {
    return (9.0/5.0) * c + 32;
}

float keCelsius(float f) {
    return (5.0/9.0) * (f - 32);
}

int main() {
    int pilihan;
    float nilai;

    printf("1. Celsius ke Fahrenheit\n");
    printf("2. Fahrenheit ke Celsius\n");
    printf("Pilih: ");
    scanf("%d", &pilihan);

    printf("Masukkan nilai suhu: ");
    scanf("%f", &nilai);

    if(pilihan == 1)
        printf("Hasil: %.2f F\n", keFahrenheit(nilai));
    else if(pilihan == 2)
        printf("Hasil: %.2f C\n", keCelsius(nilai));
    else
        printf("Pilihan tidak valid\n");

    return 0;
}