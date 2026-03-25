#include <stdio.h>

int main(){
    int n;

    printf("Masukkan jumlah data: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        printf("Masukkan angka ke-%d: ", i+1);
        scanf("%d", (arr + i));
    }

    FILE *file = fopen("data.txt", "w");

    if(file == NULL){
        printf("Gagal membuka file\n");
        return 1;
    }

    for(int i = 0; i < n; i++){
        fprintf(file, "%d ", *(arr + i));
    }

    fclose(file);

    printf("Data berhasil disimpan ke file\n");

    return 0;
}