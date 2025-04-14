#include <stdio.h>

void print_revers(int x)
{
    int a = x / 100000;
    int b = (x / 10000) % 10;
    int c = (x / 1000) % 10;
    int d = (x / 100) % 10;
    int e = (x / 10) % 10;
    int f = x % 10;
    int fedcba = f * 100000 + e * 10000 + d * 1000 + c * 100 + b * 10 + a;
    printf("%d\n", fedcba);
}

int main()
{
    int x;
    scanf("%d", &x);

    print_revers(x);

    return 0;
}
