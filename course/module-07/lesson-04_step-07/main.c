#include <stdio.h>

int main()
{   
    int x, new_x = 0;
    scanf("%d", &x);
    
    do
    {
        new_x = new_x * 10 + x % 10;    // переносим все цифры нового числа на разряд больше
                                        // и в его младший разряд записываем последнюю цифру исходного числа
        x /= 10;                        // убираем последнюю цифру исходного числа
    } 
    while (x > 0);                      // продолжаем, пока не закончатся цифры в исходном числе

    printf("%d\n", new_x);    

    return 0;
}
