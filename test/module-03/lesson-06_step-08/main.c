// undefined behaviour

#include <stdio.h>

int main() {
    int x = 3;
    int result = x++ + x++ + ++x;
    printf("%d %d\n", result, x);
    x = 3;
    result = x++;
    printf("%d\n", result);
    return 0;
}
