#include <stdio.h>

int main()
{
    int n;              // количество целых чисел
    scanf("%d", &n);

    int result = 0;     // счётчик количества чётных чисел

    for(int i = 0; i < n; i++)  // ввод чисел
    {
        int x;                  // место для текущего числа
        scanf("%d", &x);

        if(x % 2 == 0)
            result++;
    }

    printf("%d\n", result);

    return 0;
}
