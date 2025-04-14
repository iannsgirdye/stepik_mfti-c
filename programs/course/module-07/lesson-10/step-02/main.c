#include <stdio.h>

int main()
{
    int n;              // хранение количества целых чисел
    scanf("%d", &n);    // и его считывание

    int min = 1024 * 1024 * 1024 * 2 - 1;   // 2^31 - 1

    for(int i = 0; i < n; i++)
    {
        int x;              // хранение текущего числа
        scanf("%d", &x);    // и его считывание

        if(x < min)
            min = x;
    }

    printf("%d\n", min);

    return 0;
}
