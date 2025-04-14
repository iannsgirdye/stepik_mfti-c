// module4 -> lesson7 -> step1

#include <stdio.h>

int main()
{
    int x = 10;
    int * px = &x;
    int y = *px;

    printf("%p\n", px);
    printf("%d\n", y);
    
    return 0;
}
