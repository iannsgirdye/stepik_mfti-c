// module6 -> lesson2 -> step8
// Проверка знаков частного и остатка двух чисел при делении


#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);

    printf("%2d : %2d = %2d (остаток %2d)\n",  x,  y,   x  /   y,    x  %   y );
    printf("%2d : %2d = %2d (остаток %2d)\n",  x, -y,   x  / (-y),   x  % (-y));
    printf("%2d : %2d = %2d (остаток %2d)\n", -x,  y, (-x) /   y,  (-x) %   y );
    printf("%2d : %2d = %2d (остаток %2d)\n", -x, -y, (-x) / (-y), (-x) % (-y));
    return 0;
}
