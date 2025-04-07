#include <stdio.h>

int main()
{
    int n;              // количество чисел
    scanf("%d", &n);    // считывание n

    int numbers[999];   // массив для хранения чисел

    for(int i = 0; i < n; i++)      // запись n чисел в массив
        scanf("%d", &numbers[i]);

    for(int i = 0; i < n; i++)      // вывод чётных чисел массива
    {
        if(numbers[i] % 2 == 0)
            printf("%d ", numbers[i]);
    }

    for(int i = 0; i < n; i++)      // вывод нечётных чисел массива
    {
        if(numbers[i] % 2 != 0)
            printf("%d ", numbers[i]);
    }

    printf("\n");   // переход на новую строку

    return 0;
}
