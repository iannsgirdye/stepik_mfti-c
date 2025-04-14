#include <stdio.h>

int main()
{
    int element;                // хранение текущего элемента
    int sum = 0;                // накопитель суммы всех элементов

    for(int i = 0; i < 9; i++)
    {
        scanf("%d", &element);  // ввод элементов
        sum += element;         // сложение элементов
    }

    printf("%d\n", sum);        // вывод суммы элементов

    return 0;
}
