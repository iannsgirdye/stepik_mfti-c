#include <stdio.h>
#define N 1000

int main()
{
    char a[N + 1];

    while(1 == scanf("%s", a))
    {
        if(NULL != strstr(a, "bomb"))
        {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}
