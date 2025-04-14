#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


typedef int Data;
typedef unsigned int Count;

typedef struct {
    Count n;      // количество элементов в массиве
    size_t size;  // размер массива
    Data a[1];    // массив
} Stack;


// создание структуры стека
Stack *stack_create(size_t size) {
    size_t stack_size = sizeof(Stack) + (size - 1) * sizeof(Data);  // размер структуры стека в байтах
    Stack *p_stack = malloc(stack_size);                            // определение динамической памяти структуры стека
    
    if (p_stack == NULL) {                                          // если не удалось выделить динамическую память:
        exit(1);                                                    //   вызов досрочного завершения работы программы
    }
    
    p_stack->n = 0;                                                 // изначальное количество элементов в массиве стека
    p_stack->size = size;                                           // изначальное количество ячеек в массиве стека
    
    return p_stack;
}


// расширение массива стека ("скелет" как у stack_create())
Stack *stack_upgrade(Stack *p_stack) {
    size_t new_size = p_stack->size * 2;                                    // новое количество ячеек в массиве стека
    size_t new_stack_size = sizeof(Stack) + (new_size - 1) * sizeof(Data);  // новый размер структуры стека в байтах
    Stack *p_new_stack = realloc(p_stack, new_stack_size);                  // переопределение динамической памяти структуры стека

    if (p_new_stack == NULL) {                                              // если не удалось переопределить динамическую память:
        exit(1);                                                            //   вызов досрочного завершения работы программы
    }

    p_new_stack->n = p_stack->n;                                            // изначальное количество элементов в новом массиве стека
    p_new_stack->size = new_size;                                           // изначальное количество ячеек в новом массиве стека

    return p_new_stack;
}


// удаление структуры стека
Stack *stack_delete(Stack *p_stack) {
    if (p_stack != NULL) {  // если память ещё не освобождена (так как free(NULL) --- undefined behaviour):
        free(p_stack);      //   освобождение памяти
    }
    
    return NULL;
}


// возврат 1, если стек пустой, иначе возврат 0
int stack_is_empty(Stack *p_stack) {
    return (p_stack->n == 0)? 1 : 0;
}


// возврат 1, если стек полный, иначе возврат 0
int stack_is_full(Stack *p_stack) {
    return (p_stack->n == p_stack->size)? 1 : 0;
}


// добавление element на верхушку стека
Stack *stack_push(Stack *p_stack, Data element) {
    if (stack_is_full(p_stack)) {          // если стек полон:
        p_stack = stack_upgrade(p_stack);  //   расширение массива стека
    }

    if (p_stack == NULL) {                 // если не удалось расширить массив стека:
        exit(1);                           //   вызов досрочного завершения работы программы
    }

    (p_stack->a)[p_stack->n] = element;    // добавление элемента на верхушку стека
    p_stack->n ++;                         // увеличение количества элементов в массиве стека на 1

    return p_stack;
}


// удаление и возврат element с верхушки стека
Data stack_pop(Stack *p_stack) {
    if (stack_is_empty(p_stack) == 0) {   // если стек не пустой:
        p_stack->n --;                    //   уменьшение количества элементов в массиве стека на 1
        return (p_stack->a)[p_stack->n];  //   возврат снятого с верхушки стека элемента
    }
    
    exit(1);                              // если стек пустой: вызов досрочного завершения работы программы
}


void stack_print(Stack *p_stack) {
    printf("stack: ");
    for (Count i = 0; i < p_stack->n; i++) {
        printf("%d ", (p_stack->a)[i]);
    }
    printf("\n");
}


int main() {
    Stack *stack = stack_create(100);  // объявление стека
    Data   symbol;                     // текущий символ
    Data   result;                     // текущий результат применения бинарного оператора
    Data   element1, element2;         // текущие операнды

    while ((symbol = getchar()) != '=') {       // считывание символов пока не поступит знак '='
        if (isdigit(symbol)) {                  // если символ является числом:
            symbol -= '0';                      //   приведение символа к числу
            stack = stack_push(stack, symbol);  //   добавление в вершину стека
        }
        else if (symbol == '!') {               // если символ является одной из логических функций:
            element1 = stack_pop(stack);
            result = (element1)? 0 : 1;         //   выполнить соответствующую операцию
            stack = stack_push(stack, result);
        }
        else if (symbol == '|') {
            element1 = stack_pop(stack);
            element2 = stack_pop(stack);
            result = (element1 || element2)? 1 : 0;
            stack = stack_push(stack, result);
        }
        else if (symbol == '&') {
            element1 = stack_pop(stack);
            element2 = stack_pop(stack);
            result = (element1 && element2)? 1 : 0;
            stack = stack_push(stack, result);
        }
    }

    printf("%d\n", stack_pop(stack));
    stack = stack_delete(stack);

    return 0;
}
