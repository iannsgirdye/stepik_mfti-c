#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


typedef int Data;
typedef unsigned int Count;

typedef struct {
    Count n;      // количество элементов в массиве
    size_t size;  // количество ячеек в массиве
    Data a[1];    // массив
} Stack;


// создать стек размером size
Stack *stack_create(size_t size) {
    size_t stack_size = sizeof(Stack) + (size - 1) * sizeof(Data);
    Stack *p_stack = malloc(stack_size);
    
    if (p_stack == NULL) {
        exit(1);
    }

    p_stack->n = 0;
    p_stack->size = size;
    
    return p_stack;
}


// вернуть 1, если стек пустой, иначе вернуть 0
int stack_is_empty(Stack *p_stack) {
    return (p_stack->n == 0)? 1 : 0;
}


// вернуть 1, если стек полный, иначе вернуть 0
int stack_is_full(Stack *p_stack) {
    return (p_stack->size == p_stack->n)? 1 : 0;
}


// выделить дополнительное место в массиве
Stack *stack_upgrade(Stack *p_stack) {
    size_t new_size = p_stack->size * 2;
    size_t new_stack_size = sizeof(Stack) + (new_size - 1) * sizeof(Data);
    Stack *p_new_stack = realloc(p_stack, new_stack_size);

    if (p_new_stack != NULL) {
        p_new_stack->size = new_size;
        return p_new_stack;
    }
    
    return p_stack;
}


// добавить в вершину стека element
Stack *stack_push(Stack *p_stack, Data element) {
    if (stack_is_full(p_stack) == 1) {
        p_stack = stack_upgrade(p_stack);
    }

    if (p_stack == NULL) {
        exit(1);
    }
    
    p_stack->a[p_stack->n] = element;
    p_stack->n ++;
    
    return p_stack;
}


// убрать из вершины стека element и вернуть его
Data stack_pop(Stack *p_stack) {
    if (stack_is_empty(p_stack) == 0) {
        p_stack->n --;
        return (p_stack->a)[p_stack->n];
    }

    return 0;
}


void stack_print(Stack *p_stack) {
    printf("stack: ");
    for (Count i = 0; i < p_stack->n; i++) {
        printf("%c ", (p_stack->a)[i]);
    }
    printf("\n");
}


Stack *stack_delete(Stack *p_stack) {
    if (p_stack != NULL) {
        free(p_stack);
    }

    return NULL;
}


int main() {
    char * brackets_open = "([{<";
    char * brackets_close = ")]}>";

    char symbol, last_symbol = '-';
    Stack * stack = stack_create(10);

    while ((symbol = getchar()) != EOF && ispunct(symbol) != 0) {  // пока поступают скобки:
        if (strchr(brackets_open, symbol)) {                       //   если скобка открывающаяся:
            stack = stack_push(stack, symbol);                     //     положить её в стек
        }
        else {                                                     //   если скобка закрывающаяся:
            last_symbol = stack_pop(stack);                        //     достать из стека последнюю открывающуюся скобку
            
            if (last_symbol == 0) {                                //       если стек пустой:
                printf("NO\n");                                    //         последовательность неверная
                stack = stack_delete(stack);
                return 0;
            }
            else if (strchr(brackets_open, last_symbol) - brackets_open != strchr(brackets_close, symbol) - brackets_close) {
                printf("NO\n");  // если скобки не парные: последовательность неверная
                stack = stack_delete(stack);
                return 0;
            }  
        }
    }

    if (stack_is_empty(stack)) {  // если стек пустой (нашлись все пары):
        printf("YES\n");          //   последовательность верная
        stack = stack_delete(stack);
        return 0;
    }
    else {                        // если стек не пустой (нашлись не все пары):
        printf("NO\n");           //   последовательность неверная
        stack = stack_delete(stack);
        return 0;
    }
}
