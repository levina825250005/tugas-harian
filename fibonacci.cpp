#include <stdio.h>

int main() {
    int a = 1, b = 1, c, i;

    printf("%d %d ", a, b);

    for(i = 3; i <= 8; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }

    return 0;
}
