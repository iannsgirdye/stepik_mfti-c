#ifndef STACK_H
#define STACK_H


#include <stdio.h>
#include <stdlib.h>


typedef int Data;
typedef int Count;
typedef Data Zero_Data;

typedef struct {
    Count n;     // количество заполненных ячеек динамического массива
    Count size;  // размер выделенной памяти для данных стека (динамического массива в ячейках)
    Data *a;     // динамический массив, в котором хранятся данные стека,
} Stack;


void   stack_init(Stack *p_stack, Count size);
Stack *stack_create(Count size);
void   stack_push(Stack *p_stack, Data x);
Data   stack_pop(Stack *p_stack);
Data   stack_get(Stack *p_stack);
void   stack_print(Stack *p_stack);
Count  stack_size(Stack *p_stack);
int    stack_is_empty(Stack *p_stack);
int    stack_is_full(Stack *p_stack);
void   stack_clear(Stack *p_stack);
Stack *stack_destroy(Stack *p_stack);


// инициализация стека (так как можно самостоятельно создать стек в функции, а потом его инициализировать)
void stack_init(Stack *p_stack, Count size) {
    p_stack->n = 0;
    p_stack->size = size;
    p_stack->a = malloc(p_stack->size * sizeof(Data));
}


// создание И инициализация стека
Stack *stack_create(Count size) {
    Stack *p_stack = malloc(sizeof(Stack));
    stack_init(p_stack, size);
    return p_stack;
}


// добавить [Data x] в верхушку стека
void stack_push(Stack *p_stack, Data x) {
    if (stack_is_full(p_stack) == 0) {
        (p_stack->a)[p_stack->n] = x;
        p_stack->n ++;
    }
    else {
        printf("[Data %d] wasn't pushed to stack because it is full.\n", x);
    }
}


// вернуть И убрать элемент на верхушке стека
Data stack_pop(Stack *p_stack) {
    if (stack_is_empty(p_stack) == 0) {
        p_stack->n --;
        return (p_stack->a)[p_stack->n];
    }

    printf("Data wasn't popped from stack because it is empty.\n");
    Zero_Data zero_data = 0;
    return zero_data;
}


// вернуть элемент на верхушке стека без изменения состояния стека
Data stack_get(Stack *p_stack) {
    if (stack_is_empty(p_stack) == 0) {
        return (p_stack->a)[p_stack->n - 1];
    }

    printf("Data wasn't returned because stack is empty.\n");
    Zero_Data zero_data = 0;
    return zero_data;
}


// напечатать все элементы стека через пробел
void stack_print(Stack *p_stack) {
    for (int i = 0; i < p_stack->n; i++) {
        printf("%d ", (p_stack->a)[i]);
    }
    printf("\n");
}


// вернуть количество элементов в стеке
Count stack_size(Stack *p_stack) {
    return p_stack->n;
}


// вернуть 1, если стек пуст, иначе 0
int stack_is_empty(Stack *p_stack) {
    return (p_stack->n == 0)? 1 : 0;
}


// выделить дополнительное место для стека, если он полон, и вернуть, что стек пуст в случае удачного выделения
int stack_is_full(Stack *p_stack) {
    if (p_stack->size == p_stack->n) {                               // если стек полон:
        Count new_size = p_stack->size * 2; 
        Data *new_a = realloc(p_stack->a, new_size * sizeof(Data));  //   выделить новую увеличенную память
        if (new_a != NULL) {                                         //   если удалось выделить:
            p_stack->a = new_a;                                      //     обновить указатель на массив данных в стеке
            p_stack->size = new_size;                                //     обновить размер динамического массива в ячейках                                   
            return 0;                                                //     вернуть 0 (теперь стек не полон)
        }
        printf("Function realloc() return 0 in function stack_is_full()\n");
        return 1;                                                    //   если не удалось выделить: вернуть 1 (стек полон)
    }
    return 0;                                                        // если стек не полон: вернуть 0 (стек не полон)
}


// очистить стек без разрушения
void stack_clear(Stack *p_stack) {
    p_stack->n = 0;
}


// освободить память, вернуть NULL (то есть стек удалён)
Stack *stack_destroy(Stack *p_stack) {
    if (p_stack != NULL) {  // если память НЕ освобождена:
        free(p_stack->a);   //   сначала свободить память для массива данных
        p_stack->a = NULL;  
        free(p_stack);      //   потом освободить память для самого стека
    }
    return NULL;        
}


#endif  // STACK_H
