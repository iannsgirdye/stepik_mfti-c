// #include <stdio.h>

// long long int ipow(long long int a, unsigned int n, unsigned int * depth);

// int main()
// {
//     long long int a;
//     unsigned int n;
//     unsigned int d = 100;
//     scanf("%lld%u", &a, &n);
    
//     long long int result = ipow(a, n, &d);
//     printf("%lld %u\n", result, d);

//     return 0;
// }

long long int ipow(long long int a, unsigned int n, unsigned int * depth)
{
    static unsigned int real_depth = 0;
    real_depth += 1;
    if(n == 0)
    {   
        *depth = real_depth; 
        return 1;
    }
    if(n == 1)
    {
        *depth = real_depth;
        return a;
    }

    if(n % 2 == 0)
    {
        long long int result = ipow(a, n / 2, depth);
        return result * result;
    }
    else
    {
        return a * ipow(a, n - 1, depth);
    }
}
