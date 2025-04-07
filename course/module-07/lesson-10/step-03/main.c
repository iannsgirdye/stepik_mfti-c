#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int first = N;      // хранит в себе N
    int second = 0;     // будет хранить в себе перевёрнутое N

    while(N > 0)
    {
        second = second * 10 + N % 10;  // переносим все цифры на разряд старше и в свободный разряд единиц записываем последнюю цифру N
        N /= 10;                        // удаляем последнюю цифру N
    }

    printf("%s\n", (first == second)? "YES": "NO");

    return 0;
}
