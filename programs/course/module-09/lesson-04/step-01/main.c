#include <stdio.h>


int main() {
    int N;            // размер квадрата
    scanf("%d", &N);

    int result = 0;   // счётчик чёрных клеток

    char line[101];                    // 101-е место для '\0'
    for (int i = 0; i < N; i++) {
        scanf("%100s", line);          // считывание не более 100 символов в одном линии
        for (int j = 0; j < N; j++) {
            if (line[j] == '*') {
                result++;
            }
        }
    }    

    printf("%d\n", result);

    return 0;
}
