#include <stdio.h>
#define N 1000

int main()
{
    int a[N];   // массив для N чисел
    int i;      // номер текущей ячейки
    int n;      // сколько чисел дано

    scanf("%d", &n);
    
    for(i = 0; i <  n; i++)         // читаем n чисел в массив a
        scanf("%d", &a[i]);

    for(i = n - 1; i >= 0; i--)     // печатаем числа
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}
