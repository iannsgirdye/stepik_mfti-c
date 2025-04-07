#include <stdio.h>
#define N 9     // количество монет

int main()
{
    int bank_money_count[N],                                        // счётчики монет от 5000 до 1
        bank_money[N] = {5000, 1000, 500, 100, 50, 10, 5, 2, 1},    // сами монеты от 5000 до 1
        money;                                                      // необходимая сумма

    scanf("%d", &money);

    for(int i = 0; i < N; i++)
    {
        bank_money_count[i] = money / bank_money[i];            // фиксируем количество монет, помещающихся в сумму
        money %= bank_money[i];                                 // отнимаем от суммы монеты, которые зафиксировали
        printf("%d %d\n", bank_money[i], bank_money_count[i]);  // выводим номинал монеты и её количество в сумме
    }

    return 0;
}
