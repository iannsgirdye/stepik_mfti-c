#include <stdio.h>

void center(int xlt, int ylt, int xrb, int yrb, int *pxc, int *pyc)
{
    *pxc = (xrb + xlt) / 2;
    *pyc = (ylt + yrb) / 2;
}

int main()
{
    int xlt, ylt,  // верхняя левая точка
        xrb, yrb,  // нижняя правая точка
        x,   y;    // точка в центре
    scanf("%d %d %d %d", &xlt, &ylt, &xrb, &yrb);
    
    center(xlt, ylt, xrb, yrb, &x, &y);
    printf("%d %d\n", x, y);

    return 0;
}
