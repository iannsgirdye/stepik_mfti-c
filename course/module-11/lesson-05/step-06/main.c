#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 1000


void lower(char * a)
{
    for(int i = 0; i < strlen(a); i++)
        a[i] = tolower(a[i]);
}


int main()
{
    char a[N + 1];

    while(1 == scanf("%s", a))
    {
        lower(a);
        if(NULL != strstr(a, "bomb"))
        {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}
