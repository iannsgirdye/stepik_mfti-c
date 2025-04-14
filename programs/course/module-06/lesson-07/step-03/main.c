#include <stdio.h>

int main()
{
    int k, p1, p2, p3;
    scanf("%d%d%d%d", &k, &p1, &p2, &p3);

    if(p1 + p2 + p3 <= k)                   // могут уплыть за 1 раз
        printf("YES\n");

    else if(p1 + p2 <= k && p3 <= k)        // 1 и 2 уплывают, 1 или 2 возвращается,
        printf("YES\n");                    // 3 уплывает, 2 или 1 возвращается за 1 или 2

    else if(p2 + p3 <= k && p1 <= k)
        printf("YES\n");

    else if(p1 + p3 <= k && p2 <= k)
        printf("YES\n");
    
    else
        printf("NO\n"); 

    return 0;
}
