#include <stdio.h>

int main(){
int i, j, space;
int tinggi = 3;

for (i = 1; i <= tinggi; i++)
{
    for (space = 1; space <= tinggi - i; space++)
    {
        printf(" ");
    }
    for (j = 1; j <= (2 * i - 1); j++)
    {
        printf("*");
    }
    printf("\n");
}

for (i = tinggi - 1; i >= 1; i--)
{
    for (space = 1; space <= tinggi - i; space++)
    {
        printf(" ");
    }
    for (j = 1; j <= (2 * i - 1); j++)
    {
        printf("*");
    }
    printf("\n");
}
return 0;
}