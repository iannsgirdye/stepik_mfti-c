#include <stdio.h>

int main()
{
    int a[10];                  // коробка с ячейками
    int i;                      // номер текущей ячейки
    int k, n;                   // начало (k) и конец (n) отрезка нужных номеров
    
    for(i = 0; i < 10; i++)     // номера ячеек меняются
        scanf("%d", &a[i]);     // получить число шариков в ячейке с номером i

    scanf("%d%d", &k, &n);      // получить k и n
    
    for(i = k; i <= n; i++)     // номера ячеек меняются
        printf("%d ", a[i]);    // печать число из ячейки с номером i через пробел

    printf("\n");               // печать новой строки

    return 0;
}
