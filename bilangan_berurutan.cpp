#include<stdio.h>
int main(){
    int i,j;
    int baris = 4, kolom = 5;

    for (i = 0; i < baris; i++) {
    for (j = 0; j < kolom; j++) {
        if (i % 2 == 0) {
            printf("%4d", i*kolom + j + 1);
        } else {
            printf("%4d", (i+1)*kolom - j);
        }
    }
    printf("\n");
}

    return 0;
}