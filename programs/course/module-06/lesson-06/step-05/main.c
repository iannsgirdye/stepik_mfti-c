#include <stdio.h>

int main()
{
    int x, y;     // дверь
    int a, b, c;  // холодильник

    scanf("%d%d", &x, &y);
    scanf("%d%d%d", &a, &b, &c);

    if((a <= x && b <= y) || (a <= x && c <= y) || (b <= x && a <= y) || (b <= x && c <= y) || (c <= x && a <= y) || (c <= x && b <= y))
        printf("YES\n");
    else
        printf("NO\n"); 

    return 0;
}
