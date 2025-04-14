#include <stdio.h>

void mirror_seg(int *px1, int *py1, int *px2, int *py2);

int main()
{
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    mirror_seg(&x1, &y1, &x2, &y2);
    printf("%d %d %d %d\n", x1, y1, x2, y2);

    return 0;
}

void mirror_seg(int *px1, int *py1, int *px2, int *py2)
{
    *py1 *= -1;
    *py2 *= -1;
    *px1 = *px1;
    *px2 = *px2;
}
