#include <stdio.h>


int is_magic(int matrix[3][3])
{                           
    int sums[8];                                            // суммы элементов:
    sums[0] = matrix[0][0] + matrix[0][1] + matrix[0][2];   // 0-я строка
    sums[1] = matrix[1][0] + matrix[1][1] + matrix[1][2];   // 1-я строка
    sums[2] = matrix[2][0] + matrix[2][1] + matrix[2][2];   // 2-я строка
    sums[3] = matrix[0][0] + matrix[1][0] + matrix[2][0];   // 0-й столбец
    sums[4] = matrix[0][1] + matrix[1][1] + matrix[2][1];   // 1-й столбец
    sums[5] = matrix[0][2] + matrix[1][2] + matrix[2][2];   // 2-й столбец
    sums[6] = matrix[0][0] + matrix[1][1] + matrix[2][2];   // главная диагональ
    sums[7] = matrix[0][2] + matrix[1][1] + matrix[2][0];   // второстепенная диагональ

    for(int i = 0; i < 7; i++)
    {
        if(sums[i] != sums[i + 1])
        {
            printf("NO\n");
            return 0;
        }
    }

    printf("MAGIC\n");
    return 1;
}


int main()
{
    int matrix[3][3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            scanf("%d", &matrix[i][j]);
    }

    is_magic(matrix);

    return 0;
}
