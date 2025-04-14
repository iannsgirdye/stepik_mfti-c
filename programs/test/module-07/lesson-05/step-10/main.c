// module7 -> lesson5 -> step10
// Проверка цикла for

#include <stdio.h>

int main()
{
    //int x, y;
    //scanf("%d%d", &x, &y);
    int i;
    for(i = 0; i < 5; i++)
    {
        printf("> i = %d\n", i);
    }

    for(i = 0; i < 5; ++i)
    {
        printf(">> i = %d\n", i);
    }

    return 0;
}
