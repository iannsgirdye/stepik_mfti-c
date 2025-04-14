#include <stdio.h>
#include <math.h>
#define N 1300010


int read_numbers(int *numbers, int n)
{
    int max_number = 0;
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);       // Ввод чисел
        if(numbers[i] > max_number)     // Определение максимального числа
            max_number = numbers[i];
    }    

    return max_number;
}


int main()
{
    char prime[N] = {0};        // 0 = простое, 1 = составное
    
    int n;                      // Количество чисел
    scanf("%d", &n);

    int numbers[n],                                 // Массив чисел
        max_number = read_numbers(numbers, n);      // Считывание чисел и получение максимального из них

    for(int number = 1; number <= max_number; number++)     // Проходимся от 1 до максимального числа
    {   
        for(int k = 2; k <= (int)(sqrt(max_number)); k++)   // Проходимся от 2 до корня из максимального числа
        {
            if(number % k == 0 && number != k)              // Если число из внешнего цикла делится на число
            {                                               // из внутреннего цикла и они не равны,
                prime[number] = 1;                          // то помечаем, что оно составное
                break;
            }
        }
    }


    for(int i = 0; i < n; i++)          // Проходимся по введённым числам
    {
        if(prime[numbers[i]] == 0)      // Выводим те, которые простые
            printf("%d ", numbers[i]);
    }

    printf("\n");   // Перенос строки

    return 0;
}
