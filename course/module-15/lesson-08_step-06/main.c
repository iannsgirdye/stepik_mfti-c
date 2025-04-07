#include <stdio.h>
#include "stack.h"
#include "assert.h"


// Тестирование работы стека
int main() {
    Stack stack;
    
    // 1. Инициализация стека
    stack_init(&stack);

    // 2. Пустой стек
    printf("empty: %s\n", (stack_is_empty(&stack))? "YES" : "NO");
    printf("full: %s\n", (stack_is_full(&stack))? "YES" : "NO");

    // 3. Заполнение стека
    Data test_data[] = {5, 17, -3, 0, 1, 2, 3, 4};
    count test_size = sizeof(test_data) / sizeof(Data);
    assert(test_size == N);

    for (count i = 0; i < test_size; i++) {
        stack_push(&stack, test_data[i]);
        printf("push %d: ", test_data[i]);
        stack_print(&stack);
        printf("empty: %s\n", (stack_is_empty(&stack))? "YES" : "NO");
    }
    printf("full: %s\n", (stack_is_full(&stack))? "YES" : "NO");

    // 4. Опустошение стека
    for (count i = 0; i < test_size; i++) {
        Data element = stack_pop(&stack);
        assert(test_data[test_size - 1 - i] == element);
        printf("pop %d: ", element);
        stack_print(&stack);
    }
    printf("empty: %s\n", (stack_is_empty(&stack))? "YES" : "NO");
    printf("full: %s\n", (stack_is_full(&stack))? "YES" : "NO");

    return 0;
}
