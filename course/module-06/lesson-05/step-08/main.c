#include <stdio.h>

int main()
{
    float x, y;
    scanf("%f%f", &x, &y);

    if((-3 <= x && x <= 2) && (-4 <= y && y <= 6))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
