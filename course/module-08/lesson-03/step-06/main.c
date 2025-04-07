#include <stdio.h>
#define N 10

int main()
{
    int a[N];   // коробка с ячейками
    int i;      // номер текущей ячейки

    for(i = 0; i < N; i++)      // номера ячеек меняются
        scanf("%d", &a[i]);     // получить число шариков в ячейке с номером i

                                // Ищем все ячейки, в которых числа < 0
    for(i = 0; i < N; i++){     // перебираем все ячейки
        if (a[i] >= 0)          // если число в ячейке a[i] подходит
            printf("%d ", i);   // печатаем номер i
    }

    printf("\n");               // переход на новую строку

    return 0;
}
