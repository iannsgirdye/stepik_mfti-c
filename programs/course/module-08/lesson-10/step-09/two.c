#include <stdio.h>
#include <math.h>
#define N 1300010


int get_numbers(int *numbers, int n)
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


void find_is_prime(char *prime, int max_number, int n)
{   
    int k_max = sqrt(max_number);
    for(int k = 2; k <= k_max; k++)                         // Проходимся от 1 до максимального числа
    {   
        for(int number = 1; number <= max_number; number++) // Проходимся от 2 до корня из максимального числа
        {                                                   // Если число из внешнего цикла делится на число
            if(number % k == 0 && number != k)              // из внутреннего цикла и они не равны,           
                prime[number] = 1;                          // то помечаем, что оно составное
        }
    }
}


void print_is_prime(char *prime, int *numbers, int n)
{
    for(int i = 0; i < n; i++)                  // Проходимся по введённым числам и выводим простые
    {
        if(prime[numbers[i]] == 0)
            printf("%d ", numbers[i]);
    }
}


int main()
{
    char prime[N] = {0};                        // 0 = простое, 1 = составное
    int  n;                                     // Количество чисел
    scanf("%d", &n);
    
    int numbers[n],                             // Массив введённых чисел
        max_number = get_numbers(numbers, n);   // Считывание чисел и получение максимального из них

    find_is_prime(prime, max_number, n);        // Поиск простых чисел
    print_is_prime(prime, numbers, n);          // Вывод простых чисел

    printf("\n");
    return 0;
}
