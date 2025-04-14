#include <stdio.h>

int nod(int a, int b)
{
    int ost = a % b;
    if(ost == 0)
    {
        return b;
    }
    a = b;
    b = ost;
    return nod(a, b);
}

// int main()
// {
//     int a, b;
//     scanf("%d%d", &a, &b);

//     printf("%d\n", nod(a, b));

//     return 0;
// }
