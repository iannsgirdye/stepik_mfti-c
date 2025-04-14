#include <stdio.h>
#include <math.h>


float dist(int x1, int y1, int x2, int y2)
{   
    int x = x1 - x2;
    int y = y1 - y2;
    int len = x * x + y * y;
    return sqrt(len);
}

float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    float a = dist(x1, y1, x2, y2);
    float b = dist(x2, y2, x3, y3);
    float c = dist(x3, y3, x1, y1);

    float p = (a + b + c) / 2.0;
    float s = sqrt(p * (p - a) * (p - b) * (p - c));
    return s;
}

int main()
{
    int x1, y1, x2, y2, x3, y3;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

    printf("%.3f\n", area(x1, y1, x2, y2, x3, y3));

    return 0;
}
