#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    x = (x % 2 == 0)? 'G' : 'B';
    putchar(x);
    printf("\n");

    return 0;
}
