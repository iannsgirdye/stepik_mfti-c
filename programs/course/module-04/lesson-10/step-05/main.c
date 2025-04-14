#include <stdio.h>

void rotateC(int *x1, int *y1, int *x2, int *y2)
{
    int a = *x2 - *x1;         // длина
    int b = *y1 - *y2;         // высота
    int change = (a - b) / 2;
    *x1 += change;
    *y1 += change;
    *x2 -= change;
    *y2 -= change;
}

int main()
{
    int xlt, ylt,  // верхняя левая точка
        xrb, yrb;  // нижняя правая точка

    scanf("%d %d %d %d", &xlt, &ylt, &xrb, &yrb);

    rotateC(&xlt, &ylt, &xrb, &yrb);
    printf("%d %d %d %d\n", xlt, ylt, xrb, yrb);

    return 0;
}
