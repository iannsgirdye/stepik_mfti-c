#include <stdio.h>

int main()
{
    int a1, b1, a2, b2;
    scanf("%d:%d", &a1, &b1);
    scanf("%d:%d", &a2, &b2);

    int total_a = a1 + a2, total_b = b1 + b2;
    printf("%d:%d\n", total_a, total_b);

    if(total_a > total_b)
        printf("2\n");
    else if(total_a == total_b)
        printf("1\n");
    else
        printf("0\n");

    return 0;
}
