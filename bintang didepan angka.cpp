#include<stdio.h>
int main(){
    int i,j;
    int kiri = 7, kanan = 10;
    int stepkiri = 8, stepkanan = 8;

    for(i = 1; i <= 5; i++){
        for(j = 5; j >= i; j--){
            printf("*");
        }
    
        printf("%d %d\n", kiri, kanan);

        kiri  += stepkiri;
        kanan += stepkanan;

        stepkiri  += 3;   
        stepkanan -= 2;

    }

    return 0;
}