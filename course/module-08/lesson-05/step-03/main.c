#include <stdio.h>
#define N 1000

int main()
{
    int numbers[N],    // массив чисел
        n,             // количество чисел
        k,             // нужное число
        i,             // счётчик для циклов
        result;        // результат

    scanf("%d", &n);

    for(i = 0; i < n; i++)          // запись чисел в массив
        scanf("%d", &numbers[i]);

    scanf("%d", &k);

    for(i = 0; i < n; i++)
    {
        if(numbers[i] == k)     // сохраняем индекс первого попавшегося числа,
        {
            result = i;         // если число массива совпало с нужным
            break;
        }
    }

    printf("%d\n", result);

    return 0;
}
