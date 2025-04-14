#include <stdio.h>

int main()
{
    int v_in;
    scanf("%d", &v_in);

    float v_out = (v_in * 1000) / 3600.0;
    printf("%f\n", v_out);

    return 0;
}
