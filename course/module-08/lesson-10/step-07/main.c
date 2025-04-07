#include <stdio.h>


#define N 100  // максимальный размер массива


int main()
{
    int first[N];   // числа перед периодом
    int second[N];  // числа периода
    int i, j;       // индексы

    int m, n;   // числитель и знаменатель дроби
    scanf("%d%d", &m, &n);
    int ost = m;  

    for (i = 0; i < N; i++) {
        first[i] = (ost * 10) / n;  // результат деления
        ost = (m * 10) % n;         // остаток, который дальше будет делиться на знаменатель
        if (ost == m) {
            break;
        }
    } 
    
    if (i == 0) {
        printf("0,%d", (m * 10) / n);
        return 0;
    }

    seco
    for (j = 0; j < N; j++) {
        second[j] =
    }

    printf("0,");
        

    return 0;
}
