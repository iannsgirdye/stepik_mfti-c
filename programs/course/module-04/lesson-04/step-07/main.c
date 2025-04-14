#include <stdio.h>
#include <math.h>

float dist(int x1, int y1, int x2, int y2)
{   
    int x = x1 - x2;
    int y = y1 - y2;
    int len = x * x + y * y;
    return sqrt(len);
}

int main()
{
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    printf("%.3f\n", dist(x1, y1, x2, y2));    

    return 0;
}
