#include <stdio.h>

int main()
{
    int d, k;           // нужная цифра и число
    scanf("%d%d", &d, &k);
    printf("%d %d ", d, k);

    int result = 0;     // счётчик

    while(k > 0)
    {
        if(k % 10 == d)
            result++;
        k /= 10;
    }

    printf("%d\n", result);

    return 0;
}
