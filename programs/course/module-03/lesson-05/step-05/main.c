#include <stdio.h>

int main()
{
    float s, w, h, ch;  // площадь, длины одной и другой сторон, ширина стула
    int   res;

    scanf("%f%f%f", &s, &h, &ch);
    w = s / h;
    res = w / ch;

    printf("%d\n", res);

    return 0;
}
