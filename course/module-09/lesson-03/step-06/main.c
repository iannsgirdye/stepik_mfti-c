#include <stdio.h>
#define N 9

void read_matrix(int matrix[N][N])
{
    for(int i = 0; i < N; i++)          // проход строкам и столбцам
    {                                   // и запись в них введённых чисел
        for(int j = 0; j < N; j++)
            scanf("%d", &matrix[i][j]);
    }
}

int check_matrix(int matrix[N][N])
{
    int numbers_i[N + 1] = {0};     // счётчик чисел в каждой строке
    int numbers_j[N + 1] = {0};     // счётчик чисел в каждом столбце
    for(int i = 0; i < N; i++)      // проход по строкам и столбцам
    {
        for(int j = 0; j < N; j++)
        {
            numbers_i[matrix[i][j]]++;              // увеличение количества раз встречи числа в матрице 
            if(numbers_i[matrix[i][j]] > i + 1)     // если это количество > числа пройденных строк,
                return 0;                           // то поле неправильное
            
            numbers_j[matrix[j][i]]++;              // аналогично для столбцов
            if(numbers_j[matrix[j][i]] > i + 1)
                return 0;
        }
    }
    return 1;                       // после правильное, если прошло проверку
}

int check_boxes(int matrix[N][N])
{
    for(int a = 0; a < N / 3; a++)          // создание матрицы из поля, элементами которой будут квадраты
    {                                       // и проход по её строкам (a) и столбцам (b)
        for(int b = 0; b < N / 3; b++)
        {
            int numbers[N + 1] = {0};                       // счётчик чисел в каждом квадрате
            for(int i = (a * 3); i <= (a * 3 + 2); i++)     // проход по строкам и столбцам квадрата
            {
                for(int j = (b * 3); j <= (b * 3 + 2); j++)
                {
                    numbers[matrix[i][j]]++;            // увеличение количества раз встречи числа в квадрате
                    if (numbers[matrix[i][j]] > 1)      // если это количество > числа пройденных строк,
                        return 0;                       // то поле неправильное
                }
            }
        }
    }
    return 1;                               // после правильное, если прошло проверку
}

int main()
{
    int matrix[N][N];       // поле
    read_matrix(matrix);    // запись решения

    int check1 = check_boxes(matrix);   // проверка квадратов 3х3
    int check2 = check_matrix(matrix);  // проверка поля
    
    if(check1 == 1 && check2 == 1)      // вывод результата
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
