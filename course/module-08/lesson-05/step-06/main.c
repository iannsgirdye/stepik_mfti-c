#include <stdio.h>
#define N 1000          // размерность векторов

int main()
{
    int a[N], b[N],     // массивы векторов
        n,              // количество векторов в каждом массиве
        i,              // счётчик номеров для циклов
        result = 0;     // накопитель сумм произведений векторов

    scanf("%d", &n);    // считывание n

    for(i = 0; i < n; i++)      // запись векторов в 1-й массив
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++)      // запись векторов во 2-й массив
        scanf("%d", &b[i]);

    for(i = 0; i < n; i++)      // вычисление суммы произведений векторов
        result += a[i] * b[i];   

    printf("%d\n", result);     // вывод result

    return 0;
}
