#include <stdio.h>

int main()
{
    float x, y;
    scanf("%f%f", &x, &y);

    if(y <= 3 + x && y <= 3 - x && y >= -2)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
