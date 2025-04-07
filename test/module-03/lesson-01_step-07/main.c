// Проверка использования "<>" для собственного заголовочного файла

// #include <main.h>   так нельзя
#include "main.h"   // нужно вот так
#include "stdio.h"  // а так можно

int main() {
    printf("%d, %s\n", NUMBER, HELLO_WORLD);
    return 0;
}
