#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100


void new_string(char input[MAX_SIZE]) {
    char output[2 * MAX_SIZE] = {0};       // строка на выход
    char bomb[] = "bomb";                  // что заменять
    char watermelon[] = "watermelon";      // на что заменять
    size_t bomb_size = sizeof(bomb);
    size_t watermelon_size = sizeof(watermelon);

    char *start_copying = input;           // адрес символа, с которого начинать копировать

    while (1) {
        char *p_bomb = strstr(start_copying, "bomb");  // адрес начала первой "bomb"
        if (p_bomb == NULL) {                          // остановка цикла, если не нашлась "bomb"
            break;
        }
        size_t before_bomb = p_bomb - start_copying;   // количество символов до первого символа "bomb"

        strncat(output, start_copying, before_bomb);   // копирование символов до первого символа "bomb" в новую строку
        strncat(output, watermelon, watermelon_size);  // дописывание к скопированным символам "watermelon"
    
        start_copying += before_bomb + bomb_size - 1;  // адрес первого символа за "bomb", с которого начинать копировать
    }
    
    strcat(output, start_copying);         // копирование символов после последней "bomb"
    printf("%s", output);
}


int main() {
    char input[MAX_SIZE];
    while (fgets(input, MAX_SIZE - 1, stdin) != NULL) {  // Считывание до тех пор, пока не поступит пустая строка
        new_string(input);
    }
    printf("\n");
    
    return 0;
}
