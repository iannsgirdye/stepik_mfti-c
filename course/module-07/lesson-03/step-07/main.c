#include <stdio.h>

int main()
{
    int money,      // бюджет
        price,      // цена
        delta,      // изменение цены
        wday = 0;   // день недели

    scanf("%d%d%d", &price, &delta, &money);
    
    while(money >= price)
    {
        wday++;                         // делаем следующий день недели
        if(wday % 7 == 1 && wday != 1)  // Если наступил не первый понедельник,
            price += delta;             // то увеличиваем цену риса

        if(money >= price)              // Если хватает денег (ведь после увеличения может не хватать),
            money -= price;             // то покупаем рис
        else
            wday--;                     // иначе уменьшаем количество дней покупок
    }

    printf("%d", wday);

    return 0;
}
