#include <stdio.h>

int main()
{
    int N, K;               // N --- ножки
    scanf("%d%d", &N, &K);  // K --- столешницы
    
    if(N / 4 >= K)
        printf("%d\n", K);
    else
        printf("%d\n", N / 4);

    return 0;
}
