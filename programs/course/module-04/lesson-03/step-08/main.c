#include <stdio.h>


float celsius(int fahr)
{
    return (fahr - 32) / (9 / 5.0);
}


int main()
{
    int   fahr;
    float cel;

    scanf("%d", &fahr);
    cel = celsius(fahr);

    printf("Если F = %d, то C = %.2f\n", fahr, cel); 
    return 0;
}
