#include <stdio.h>

int main()
{
    float imt, m, h;
    scanf("%f%f", &m, &h);

    imt = m / (h * h);
    printf("%f", imt);

    return 0;
}
