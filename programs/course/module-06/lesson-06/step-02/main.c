#include <stdio.h>

int main()
{
    char letter1, letter2;
    int  number1, number2;
    scanf("%c%d-%c%d", &letter1, &number1, &letter2, &number2);
    printf("%c%d-%c%d\n", letter1,  number1,  letter2,  number2);

    if(letter1 != letter2 && number1 != number2)
        printf("NO\n");
    else
        printf("YES\n");

    return 0;
}
