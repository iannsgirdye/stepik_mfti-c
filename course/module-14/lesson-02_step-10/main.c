#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 1000


char *resize(char *old, size_t new_len) {
    char *new = realloc(old, new_len);
    
    if (new == NULL) {
        free(old);
        printf("Error: realloc()\n");
        exit(EXIT_FAILURE);
    }

    return new;
}


char *replace(const char *src) {
    char *new = malloc(1);  // выделение места для нуля-терминатора
    if (new == NULL) {
        printf("Error: malloc()\n");
        exit(EXIT_FAILURE);
    }
    new[0] = '\0';

    const char *bomb = "bomb";              // что заменять
    const char *watermelon = "watermelon";  // на что заменять
    size_t bomb_len = strlen(bomb);
    size_t watermelon_len = strlen(watermelon);

    const char *p_start = src;                   // адрес символа, с которого начинать копирование
    const char *p_bomb = strstr(p_start, bomb);  // адрес первого символа в "bomb"

    while (p_bomb != NULL) {  // пока "bomb" есть в src после p_start
        // количество символов до первого символа в "bomb"
        size_t before_bomb_len = p_bomb - p_start;     
        
        // количество символов в new с учётом '\0'
        size_t new_len = strlen(new) + 1 + watermelon_len + before_bomb_len;
        
        new = resize(new, new_len);  // перевыделение памяти

        // копирование символов до первого символа подстроки "bomb" в новую строку
        strncat(new, p_start, before_bomb_len);

        // дописывание к скопированным символам подстроки "watermelon"
        strcat(new, watermelon);

        // p_start = первый символ после последней бомбы
        p_start += before_bomb_len + bomb_len;
        
        // указатель на следующую подстроку "bomb" в строке src
        p_bomb = strstr(p_start, bomb);
    }

    // количество уже записанных символов + количество символов после последней "bomb"
    size_t new_len = strlen(new) + strlen(p_start) + 1;

    new = resize(new, new_len);

    // дописывание оставшихся символов после последней "bomb"
    strcat(new, p_start);

    return new;
}


int main() {
    char s[N];   // нужно объявить переменную - место для читаемой строки
    char * d;    // указатель на динамический массив, память еще не выделена

    while (NULL != fgets(s, N, stdin)) {  // пока можем прочитать строку
        d = replace(s);                   // тут память выделяем
        printf("+++%s+++\n", d);
        free(d);                          // тут память освобождаем
    }

    return 0;
}
