#include <stdio.h>

int main()
{
    int g1, s1, k1, g2, s2, k2;
    scanf("%d%d%d", &g1, &s1, &k1);
    scanf("%d%d%d", &g2, &s2, &k2);

    int all_k1 = ((g1 * 17) + s1) * 29 + k1;
    int all_k2 = ((g2 * 17) + s2) * 29 + k2;
    int all_k = all_k1 + all_k2;

    int total_g = all_k / (29 * 17);
    int total_s = (all_k - total_g * 29 * 17) / 29;
    int total_k = all_k - total_g * 29 * 17 - total_s * 29;

    printf("%d %d %d\n", total_g, total_s, total_k);
    
    return 0;
}
