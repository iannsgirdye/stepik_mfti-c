#include <stdio.h>

int rusDel(int a, int b)
{   
    static int part = 0;
    int mult, rem;

    if(a == 0)
        printf("1\n");
    
    else
    {
        if(a % 2 == 0)
            mult = 2, rem = 0, a /= 2;
        else
            mult = 1, rem = 1, a -= b;

        if(a != 0)
            printf("%d %d %d\n", a, mult, rem);
        rusDel(a, b);
        
        int new_part = part * mult + rem;
        if(a != 0)
            printf("%d * %d + %d = %d\n", part, mult, rem, new_part);
        part = new_part;
    }
    
    return part;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    printf("%d\n", rusDel(a, b));

    return 0;
}
