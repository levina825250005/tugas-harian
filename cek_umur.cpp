#include <stdio.h>

int main(){
    int umur;

    printf("Masukkan umur: ");
    scanf("%d", &umur);

    if (umur >= 60){
        printf("Kategori: LANSIA\n");
    }
    else if (umur >= 18){
        printf("Kategori: DEWASA\n");
    }
    else if (umur >= 13){
        printf("Kategori: REMAJA\n");
    }
    else{
        printf("Kategori: ANAK-ANAK\n");
    }
}