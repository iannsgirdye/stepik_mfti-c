#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);

    if(x % 15 != 0 && (x % 3 == 0 || x % 5 == 0))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
