#include <stdio.h>

int main() {
    int M, N;

    int matriks[100][100];
    int hasil[100][100];

    printf("Masukkan nilai M : ");
    scanf("%d", &M);

    printf("Masukkan nilai N : ");
    scanf("%d", &N);

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &matriks[i][j]);
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            hasil[j][M - 1 - i] = matriks[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("%d ", hasil[i][j]);
        }
        printf("\n");
    }

    return 0;
}