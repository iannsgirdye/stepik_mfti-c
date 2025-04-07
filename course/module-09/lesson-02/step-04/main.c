#include <stdio.h>

int sum_col(int a[3][3], int icol)
{
    int sum = 0;
    for(int i = 0; i < 3; i++)
        sum += a[i][icol];
    return sum;
}

int main()
{
    int a[3][3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
    }

    printf("%d\n", sum_col(a, 2));

    return 0;
}
