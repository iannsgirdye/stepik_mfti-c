#include <stdio.h>

int main() 
{
    int k_rice, k_veg;               // ввод данных
    scanf("%d%d", &k_rice, &k_veg);

    int result = k_rice + k_veg * 2;
    printf("%d\n", result);

    return 0;
}
