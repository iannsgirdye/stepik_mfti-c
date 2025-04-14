// module6 -> lesson2 -> step12
// Операции над вещественными числами

#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main()
{
    float a, b;
    scanf("%f%f", &a, &b);
    printf("> %f + %f = %f\n", a, b, a + b);
    printf("> %f - %f = %f\n", a, b, a - b);
    printf("> %f * %f = %f\n", a, b, a * b);
    printf("> %f / %f = %f\n", a, b, a / b);

    if (0.1 + 0.2 + 0.3 == 0.6)
        printf(">> True\n");
    else
        printf(">> False\n");

    if (fabs((0.1 + 0.2 + 0.3) - 0.6) < EPSILON)
        printf(">>> True\n");
    else
        printf(">>> False\n");
    
    return 0;
}
