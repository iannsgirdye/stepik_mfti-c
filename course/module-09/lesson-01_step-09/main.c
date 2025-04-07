#include <stdio.h>

int main()
{
    int a[3][3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
    }

    a[1][2] *= 10;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    printf("\n");
    return 0;
}
