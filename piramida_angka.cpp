#include<stdio.h>
int main(){
    int i,j;
    int spasi;
    int angka;

    for( i = 0; i <=4; i++){
        for(spasi = 0; spasi < 4-i; spasi++){
            printf("  ");
        }
        angka = 1;
        for(j = 0; j <= i; j++){
            printf("%4d", angka);
            angka = angka * (i - j) / (j + 1);
        }
        printf("\n");
    }

    return 0;
}