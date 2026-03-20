#include <stdio.h>

int faktorial(int x) {
    int f = 1;
    for (int i = 1; i <= x; i++) f *= i;
    return f;
}

int main() {
    int n;
    
    printf("Masukkan jumlah baris: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int s = 0; s < n - i; s++) printf(" ");
        for (int j = 0; j <= i; j++) {
            int val = faktorial(i) / (faktorial(j) * faktorial(i - j));
            printf("%d ", val);
        }
        printf("\n");
    }
    return 0;
}