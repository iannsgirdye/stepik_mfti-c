#include <stdio.h>
#define N 10

int main()
{
    int a[N],       // массив
        i,          // счётчик для цикла
        k, n,       // числа для условия
        sum = 0;    // накопитель для нужных чисел

    for(i = 0; i < N; i++)  // запись N чисел в массив
        scanf("%d", &a[i]);

    scanf("%d%d", &k, &n);  // получение k и n
    for(i = k; i < n; i++)  // суммирование нужных чисел массива
        sum += a[i];

    printf("%d\n", sum);    // вывод результата

    return 0;
}
