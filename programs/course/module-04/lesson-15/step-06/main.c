#include <stdio.h>

int rusMult(int a, int b);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", rusMult(a, b));
    return 0;
}

int rusMult(int a, int b)
{   
    static int res = 0;
    printf("%d %d\n", a, b);

    if(b > 1)
    {   
        int ost = b % 2;
        if(ost == 1)
        {
            res += a;
        }

        res = rusMult(a * 2, b / 2);
        printf("%d %d %d %d\n", res, a / 2, ost, res + (a / 2) * ost);
        res += (a / 2) * ost;
    }
    else
    {
        res = a;
        printf("%d\n", a);
    }

    return res;
}
