#include <stdio.h>

int main()
{
    int bell, nBell;
    scanf("%d%d", &bell, &nBell);
    printf("%d\n", (int)(((bell + nBell) / 2.0) * (nBell - bell + 1)));  // сумма арифметической прогрессии

    return 0;
}
