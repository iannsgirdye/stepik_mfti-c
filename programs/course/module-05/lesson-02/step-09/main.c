#include <stdio.h>

int main()
{
    char letter = getchar();
    char number = getchar();

    putchar(letter - 1);  // top
    putchar(number);
    printf(" ");

    putchar(letter);      // right
    if(number == '9')
        printf("10");
    else
        putchar(number + 1);
    printf(" ");

    putchar(letter + 1);  // bottom
    putchar(number);
    printf(" ");

    putchar(letter);      // left
    putchar(number - 1);
    printf("\n");

    return 0;
}
