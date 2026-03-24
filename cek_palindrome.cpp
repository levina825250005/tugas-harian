//palindrome merupakan karakter yang terbaca sama baik dari depan maupun belakang
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len, flag = 0;

    printf("Masukkan kata: ");
    scanf("%s", str);

    len = strlen(str);

    for(i = 0; i < len / 2; i++) {
        if(str[i] != str[len - i - 1]) {
            flag = 1;
            break;
        }
    }

    if(flag)
        printf("Bukan palindrome\n");
    else
        printf("Palindrome\n");

    return 0;
}