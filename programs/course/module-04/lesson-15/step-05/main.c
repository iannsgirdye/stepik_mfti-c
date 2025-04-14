// #include <stdio.h>

void simpleFactors(unsigned int a, unsigned int last, unsigned int n)
{
    if(a % last == 0)               // 8 % 2 == 0
    {
        a /= last;                  // a = 4
        n += 1;                     // n = 1
        simpleFactors(a, last, n);  // Имеем: 2^1
    }
    
    else
    {   
        if(a > 1)
        {
            simpleFactors(a, last + 1, 0);
        }
    
        if(n == 1)
            printf("%u ", last);
            
        else if(n > 1)
            printf("%u^%u ", last, n);
    }
}

// int main()
// {
//     unsigned int a,         // Положительное целое число, которое раскладывается на простые сомножители
//                  last = 2,  // Предполагаемый сомножитель для проверки делимости (вначале 2)
//                  n = 0;     // Степень сомножителя в числе (вначале 0)

//     scanf("%u", &a);
//     simpleFactors(a, last, n);

//     return 0;
// }
