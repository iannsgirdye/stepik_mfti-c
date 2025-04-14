#include <stdio.h>


float fahr(int cel)
{
    return ((cel * 9) / 5.0) + 32;
}


int main()
{
    float cel;
    float far;

    scanf("%f", &cel);
    far = fahr(cel);
    printf("Если C = %f, то F = %.2f\n", cel, far);

    return 0;
}
