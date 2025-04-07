#include <stdio.h>

int main()
{
    int n, k_rice, k_veg;
    scanf("%d%d%d", &n, &k_rice, &k_veg);
    printf("%d %d %d\n", n, k_rice, k_veg);

    int total = k_rice + k_veg * 2;
    if(n >= total)
        printf("%d\nYES\n", total);
    else
        printf("%d\n", total);

    return 0;
}
