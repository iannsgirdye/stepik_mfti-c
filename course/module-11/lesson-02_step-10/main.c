#include <stdio.h>
#include <string.h>     // для strcmp()

int main()
{
    char s[10];         // массив для строк
    int steps;          // место для шагов
    int x = 0, y = 0;   // координаты клада

    scanf("%9s", s);
    while(0 != strcmp(s, "Treasure!"))
    {
        scanf("%d", &steps);
        
        if(0 == strcmp(s, "North"))
            y += steps;
        else if (0 == strcmp(s, "South"))
            y -= steps;
        else if (0 == strcmp(s, "East"))
            x += steps;
        else
            x -= steps;

        scanf("%9s", s);
    }       

    printf("%d %d\n", x, y);
    return 0;
}
