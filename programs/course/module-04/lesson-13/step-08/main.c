#include <stdio.h>
#define min2time(mm, h, m) (h = ((mm) / 60) % 24, m = (mm) % 60)

int main()
{
    // код с платформы --- начало
    int h, m, mm;
    scanf("%d", &mm);

    min2time(mm, h, m);
    printf("%02d:%02d\n", h, m);

    min2time(mm+65, h, m);
    printf("%02d:%02d\n", h, m);
    // код с платформы --- конец

    return 0;
}
