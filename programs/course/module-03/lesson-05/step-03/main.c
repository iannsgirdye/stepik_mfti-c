#include <stdio.h>

int main()
{
    int round, total;
    scanf("%d%d", &round, &total);

    printf("%d %d", total / round, total % round);

    return 0;
}
