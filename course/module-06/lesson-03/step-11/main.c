#include <stdio.h>

void in_zone(int x)
{
    if(x < 37 || x >= 146)
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
