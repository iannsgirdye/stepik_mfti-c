#include <stdio.h>

int main()
{
    int n, m;                       // размеры матрицы
    scanf("%d%d", &n, &m);

    int A[n][m];                    // сама матрица

    for(int i = 0; i < n; i++)      // запись матрицы
    {
        for(int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);
    }

    int k;                          // число, на которое нужно умножить матрицу
    scanf("%d", &k);

    for(int i = 0; i < n; i++)      // умножение матрицы на k
    {                               // и её вывод
        for(int j = 0; j < m; j++)
        {
            A[i][j] *= k;
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
