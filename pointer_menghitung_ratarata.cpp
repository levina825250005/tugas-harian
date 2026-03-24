#include <stdio.h>

int main() {
    int n, i;
    float total = 0;

    printf("Jumlah nilai: ");
    scanf("%d", &n);

    float nilai[n];
    float *ptr;

    ptr = nilai; 

    for(i = 0; i < n; i++) {
        printf("Nilai ke-%d: ", i+1);
        scanf("%f", (ptr + i)); 
    }

    for(i = 0; i < n; i++) {
        total += *(ptr + i);
    }

    printf("Rata-rata: %.2f\n", total / n);

    return 0;
}