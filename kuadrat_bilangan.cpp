#include<stdio.h>
int main(){
    int perkalian;
    int j = 1;

    for (int i = 0; i < 4; i++){
        perkalian = j*j;
        printf("%dx%d = %d\n", j,j, perkalian);
        j *= 2;
    }
    return 0;
}