#include <stdio.h>

void mirror(int *px)
{
    *px *= -1;
}

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    
    mirror(&x);
    printf("%d %d\n", x, y);
    
    return 0;
}
