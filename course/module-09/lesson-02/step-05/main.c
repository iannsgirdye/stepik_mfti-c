#include <stdio.h>

int sum_diag(int a[3][3])
{
    int sum = 0;
    for(int k = 0; k < 3; k++)
        sum += a[k][k];
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

    printf("%d\n", sum_diag(a));

    return 0;
}
