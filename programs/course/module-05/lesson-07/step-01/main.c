#include <stdio.h>

typedef struct{
    int h; // часы
    int min; // минуты (от 0 до 59)
}TicTac;


TicTac after(TicTac a, int min)
{   
    int all_min = a.h * 60 + a.min + min;  // Вычисляем общее количество минут
    a.h = (all_min / 60) % 12;             // Вычисляем итоговые часы
    a.min = all_min % 60;                  // Вычисляем итоговые минуты
    return a;                              // Возвращаем преобразованную структуру
}

void forward(TicTac * me, TicTac a)
{
    int all_min = (me->h) * 60 + (me->min) + a.h * 60 + a.min;  // Вычисляем общее количество минут
    me->h = (all_min / 60) % 12;                                // Вычисляем итоговые часы
    me->min = all_min % 60;                                     // Вычисляем итоговые минуты
}

void backward(TicTac * me, TicTac a)
{
    int all_min = (me->h) * 60 + (me->min) - a.h * 60 - a.min;  // Вычисляем общее количество минут
    if(all_min < 0)
        all_min = (60 * 12) + all_min;
    me->h = (all_min / 60) % 12;                                // Вычисляем итоговые часы
    me->min = all_min % 60;                                     // Вычисляем итоговые минуты
}

int isEqualTime(TicTac a, TicTac b)
{
    return (a.h == b.h) && (a.min == b.min);  // Часы и минуты должны совпадать между собой
}

void printTic(TicTac a)
{
    printf("%02d:%02d\n", a.h, a.min);
}
