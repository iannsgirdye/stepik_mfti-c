#include <stdio.h>

int main()
{
    int d;          // хранение цифры
    int c;          // переменная для записи числа по одной цифре
    d = getchar();  // запись цифры

    int result = 0;     // счётчик нужных цифр

    printf("%c", d);   // вывод цифры

    while((c = getchar()) != EOF)  // перебор цифр числа
    {  
        if(c == d)
            result++;
        printf("%c");
    }

    printf(" %d\n", result);      // вывод пробела между числом и результатом и сам результат

    return 0;
}
