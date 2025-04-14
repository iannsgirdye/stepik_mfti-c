#include <stdio.h>

int sum_row(int a[3][3], int irow)
{
    int sum = 0;                // накопитель суммы
    for(int j = 0; j < 3; j++)  // вычисление суммы
        sum += a[irow][j];
    return sum;                 // возврат суммы
}


int main()
{
    int a[3][3];                    // место для матрицы
    
    for(int i = 0; i < 3; i++)      // заполнение матрицы
    {
        for(int j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
    }

    printf("%d\n", sum_row(a, 1));  // вывод суммы средней строки

    return 0;
}
