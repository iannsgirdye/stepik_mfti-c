#include <stdio.h>
#define N 5

int main()
{
    int a[N],               // коробка с ячейками
        i,                  // номер текущей ячейки
        sum = 0;            // накопитель количества шариков
    
    for(i = 0; i < N; i++)  // читаем N чисел в массив a и находим их сумму
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    printf("%d\n", sum);    // печатаем сумму

    return 0;
}
