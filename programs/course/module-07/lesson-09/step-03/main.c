#include <stdio.h>

int main()
{
    int n;  // количество целых чисел
    scanf("%d", &n);

    int min = 2147483647;  // максимальное положительное число в signed int (2^31 - 1)

    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        
        printf("%d ", x);

        if(x < min)
            min = x;
    }

    printf("\n%d\n", min);

    return 0;
}
