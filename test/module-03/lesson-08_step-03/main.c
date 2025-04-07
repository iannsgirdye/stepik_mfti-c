#include <stdio.h>
#include <math.h>

int main() {
    double a = 2.3;
    double b = -3.2;

    printf("%lf %lf %lf %d\n", ceil(a), floor(a), round(a), (int)a);
    printf("%lf %lf %lf %d\n", ceil(b), floor(b), round(b), (int)b);

    return 0;
}
