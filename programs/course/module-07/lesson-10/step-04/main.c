#include <stdio.h>

int main()
{
    long long int n;                    // n = a^k
    short int k;
    int a = 1;                 

    scanf("%lld%hd", &n, &k);
A:
    for(int i = 2; i < n; i++)          // перебор целых чисел от 2 до n
    {   
        int mnoz = i;                   // переменная-аналог i, чтобы не ломать внешний цикл
        for(int j = 1; j < k; j++)      // возведение mnoz (i) в степень k
            mnoz *= i;
        
        if(n % mnoz == 0)
        {
            n /= mnoz;
            printf("%d %lld\n", i, n);
            a *= i;                     // формирование результат
            goto A;                     // перебор вновь, так как число может входить несколько раз
        }                               // (например, 4^2 = 2^2 * 2^2)
    }

    printf("%d\n", (n == 1)? a: -1);    // вывод a, если n = a^k, иначе вывод -1
    
    return 0;
}
