#include <stdio.h>

int main()
{
    char letter = getchar();
    char number = getchar();

    putchar(letter);
    putchar(number + 1);
    printf("\n");

    return 0;
}
