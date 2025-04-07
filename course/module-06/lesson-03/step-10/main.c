#include <stdio.h>

void in_zone(int x)
{
    if(-25 <= x && x < 37)
        printf("%d YES\n", x);
    else
        printf("%d NO\n", x);
}

int main()
{
    int x;
    scanf("%d", &x);
    in_zone(x);

    return 0;
}
