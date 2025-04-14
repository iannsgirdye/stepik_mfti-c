#include <stdio.h>

int main()
{
    int n;              // количество натуральных чисел
    scanf("%d", &n);    // считывание n
    
    int result = 0;     // накопитель чётных чисел

    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        
        if(x % 2 == 0)
            result += x;
    }

    printf("%d", result);

    return 0;
}
