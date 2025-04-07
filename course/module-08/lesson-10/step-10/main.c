#include <stdio.h>

int main()
{
    short int all_id[1001];     // Список всех id [0; 1000]
    short int n;                // Количество покупок
    short int result = 0;       // Счётчик количества покупателей
    scanf("%hd", &n);

    for(int i = 0; i < n; i++)
    {
        int timestamp;
        short int id;
        int recept_id;
        scanf("%d%hd%d", &timestamp, &id, &recept_id);

        all_id[id]++;
        if(all_id[id] == 1)
            result++;
    }

    printf("%hd\n", result);

    return 0;
}
