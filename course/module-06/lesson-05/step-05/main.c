#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d:%d", &a, &b);
    printf("%d:%d\n", a, b);

    if(a > b)
        printf("2\n");
    else if(a == b)
        printf("1\n");
    else
        printf("0\n");

    return 0;
}
