#include <stdio.h>

void read_matrix(int n, int m, int a[n][m])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    }
}

void print_matrix(int n, int m, int c[n][m])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
}

int sum_matrix(int n, int m, int a[n][m], int b[n][m], int c[n][m])
{   
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            c[i][j] = a[i][j] + b[i][j];
    }
    return c;
}

int main()
{
    int n, m;                       // размеры матриц
    scanf("%d%d", &n, &m);
    int A[n][m], B[n][m], C[n][m];  // хранение матриц

    read_matrix(n, m, A);           // запись матрицы A
    read_matrix(n, m, B);           // запись матрицы B
    sum_matrix(n, m, A, B, C);      // запись элементов a + b в матрицу C
    print_matrix(n, m, C);          // вывод матрицы C

    return 0;
}
