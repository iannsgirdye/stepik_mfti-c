#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#define N 8


typedef int Data;
typedef unsigned int count;

typedef struct {
    Data a[N];  // место для хранения данных
    count n;    // количество элементов в стеке
} Stack;


void stack_init(Stack * s);
void stack_push(Stack * s, Data x);
Data stack_pop(Stack * s);
Data stack_get(Stack * s);
void stack_clear(Stack * s);
void stack_print(Stack * s);
int  stack_size(Stack * s);
int  stack_is_empty(Stack * s);
int  stack_is_full(Stack * s);


/* необходимые действия для создания и инициализации стека 
(когда мы создаем локальную переменную, то она не инициализируется 0, т.е. в поле n может лежать любое число) */
void stack_init(Stack * s) {
    s->n = 0;
}


/* кладет число х в стек */
void stack_push(Stack * s, Data x) {
    if (stack_is_full(s) == 0) {
        (s->a)[s->n] = x;
        s->n ++;
    }
}

/* достает одно число из стека и возвращает его */
Data stack_pop(Stack * s) {
    if (stack_is_empty(s) == 0) {
        s->n --;
        return (s->a)[s->n];
    }
    return 0;
}


/* возвращает число, лежащее на верхушке стека, не изменяя состояния стека */
Data stack_get(Stack * s) {
    return (s->a)[(s->n) - 1];
}


/* очищает стек (функция stack_is_empty должна вернуть 1) */
void stack_clear(Stack * s) {
    s->n = 0;
}


/* распечатывает через пробел числа, лежащие в стеке, с самого первого до верхнего, в конце переводит строку */
void stack_print(Stack * s) {
    for (unsigned int i = 0; i < s->n; i++) {
        printf("%d ", (s->a)[i]);
    }
    printf("\n");
}


/* возвращает количество элементов, лежащих в стеке */
int stack_size(Stack * s) {
    return s->n;
}


/* возвращает 1 если стек пуст, иначе возвращает 0 */
int stack_is_empty(Stack * s) {
    return (s->n == 0)? 1 : 0;
}


/* возвращает 1 если стек полон (в него нельзя добавлять данные, это приведет к переполнению), иначе возвращает 0 */
int stack_is_full(Stack * s) {
    count stack_size = sizeof(s->a) / sizeof(Data);
    return (s->n == stack_size)? 1 : 0;
}


#endif  // STACK_H
