#include <stdio.h>

int main()
{
    int rub, kop, n, rest;

    scanf("%d%d", &rub, &kop);

    kop = rub * 100 + kop;
    n = kop / 106;
    rest = kop % 106;
    
    printf("%d %d\n", n, rest);

    return 0;
}
