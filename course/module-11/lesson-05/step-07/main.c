#include <stdio.h>
#include <string.h>


int main()
{
    char a[4] = {'c', 'c', 'c', 'c'};
    int result = 0;

    while(1 == scanf("%c", &a[0]))
    {   
        if(a[3] == 'b' && a[2] == 'o' && a[1] == 'm' && a[0] == 'b')
            result++;
        a[3] = a[2], a[2] = a[1], a[1] = a[0];
    }

    printf("%d\n", result);
    return 0;
}
