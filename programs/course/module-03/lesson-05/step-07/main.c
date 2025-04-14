#include <stdio.h>

int main()
{
    int n, day;
    scanf("%d%d", &n, &day);
    
    // вычитаем из общего числа дней в месяце те дни, которые перед первым понедельником
    int necessary_days = n - day + 1;  

    // количество полных недель
    int full_weeks = necessary_days / 7;

    // количество понедельников = количество полных недель + количество неполных недель
    int mondays = full_weeks + (necessary_days - 7 * (full_weeks - 1) - 1) / 7;
    printf("%d\n", mondays);

    return 0;
}
