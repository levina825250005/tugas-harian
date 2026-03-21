#include <stdio.h>

int main() {
    char ch = 'A'; 
    int i, j, k; 
    int n = 4; 
    for(i = 1; i <= n; i++) {
        for(k = 1; k <= n - i; k++) {
            printf("  ");
        }

        for(j = 1; j <= i; j++) {
            printf("%c ", ch);
            ch++;
        }
        printf("\n");
    }

    return 0;
}