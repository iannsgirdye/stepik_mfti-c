#include <stdio.h>

int main()
{
    int person,         // рост человека
        highest = 0,    // счётчик количества высоких людей
        people = 0 ;    // счётчик количество людей в целом

    while(1 == scanf("%d", &person))    // пока считывается рост человека
    {
        people++;                       // увеличиваем количество людей
        if(person > 170)                // если рост человека >170,
            highest++;                  // то увеличиваем количество высоких людей
    }

    printf("%d %d\n", people, highest);

    return 0;
}
