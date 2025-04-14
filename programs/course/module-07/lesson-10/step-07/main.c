#include <stdio.h>

int main()
{
    int opened = 0, closed = 0;     // счётчик открытых и закрытых скобок
    int c;                          // место для символов
    int result = '+';               // '+' — хорошо, '-' — плохо

    while ((c = getchar()) != EOF)
    {
        if(c == '(')
            opened++;
        else if(c == ')')
            closed++;
        
        if(closed > opened)         // потому что если больше открытых,
        {
            result = '-';           // то можно доставить закрытые,
            break;                  // но к поставленным закрытым уже доставить открытые
        }
    }

    if(closed != opened)            // тем более нельзя
        result = '-';                 

    printf("\n%s\n", (result == '+')? "YES": "NO");
    
    return 0;
}
