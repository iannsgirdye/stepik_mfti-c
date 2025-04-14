#include <stdio.h>
#define N (100)

int main()
{
    int i,              // счётчик индексов в циклах
        n;              // количество нанятых работников (от 1 до 100)
    scanf("%d", &n);
    
    int money[N],       // изначальные зарплаты работников
        sum = 0,        // счётчик количества монет, которые получили работники
        money_back = 0; // счётчик количества монет, которые вернутся купцу


    for(i = 0; i < n; i++)          // запись количеств монет в массив
    {                               // и вычисление суммы монет, которые получили работники
        scanf("%d", &money[i]);
        sum += money[i];
    }

A:
    for(i = 0; i < n; i++)                                  // уравнивание монет
    {   
        int money_of_two = money[i] + money[(i + 1) % n];   // i = n - 1: money[(i + 1) % n] = money[0]
        if(money_of_two % 2 != 0)
        {
            money_of_two--;
            money_back++;
        }
        money[i] = money_of_two / 2;
        money[(i + 1) % n] = money_of_two / 2;
    }
    

    for(i = 0; i < n; i++)          // проверка, что у всех одинаковое количество монет 
    {
        if(money[i] != money[(i + 1) % n])
            goto A;
    }

    printf("%d %d\n", money_back, money[0]);

    return 0;
}
