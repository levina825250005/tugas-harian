#include <stdio.h>

void bagi(int *arr, int n, int *arr1, int *arr2){
    int tengah = n / 2;

    for(int i = 0; i < tengah; i++){
        *(arr1 + i) = *(arr + i);
    }

    for(int i = tengah; i < n; i++){
        *(arr2 + (i - tengah)) = *(arr + i);
    }
}

void ganda(int *arr, int n, int *arrBaru){
    for(int i = 0; i < n; i++){
        *(arrBaru + i) = *(arr + i);
    }

    for(int i = n; i < 2*n; i++){
        *(arrBaru + i) = 0;
    }
}

int main(){
    int n;
    int i;

    printf("Masukkan jumlah elemen array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Masukkan %d angka:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", (arr + i));
    }

    int tengah = n / 2;

    int arr1[tengah];
    int arr2[n - tengah];
    int arrBaru[2*n];

    bagi(arr, n, arr1, arr2);
    ganda(arr, n, arrBaru);

    printf("\nArray awal: ");
    for(i = 0; i < n; i++){
        printf("%d ", *(arr + i));
    }

    printf("\n\n=== Membagi 2 Array ===");
    printf("\nArray 1: ");
    for(i = 0; i < tengah; i++){
        printf("%d ", *(arr1 + i));
    }

    printf("\nArray 2: ");
    for(i = 0; i < n - tengah; i++){
        printf("%d ", *(arr2 + i));
    }

    printf("\nArray hasil gandakan: ");
    for(i = 0; i < 2*n; i++){
        printf("%d ", *(arrBaru + i));
    }

    return 0;
}