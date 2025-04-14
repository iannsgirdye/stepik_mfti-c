#include <stdio.h>
#include "stack.h"


void test0() {
    Stack * sp = stack_create(3);

    printf("is_empty=%d\n", stack_is_empty(sp));    // is_empty = 1
    printf("size=%d\n", stack_size(sp));            // size = 0

    stack_push(sp, 5);
    stack_push(sp, 19);
    stack_push(sp, -2);
    stack_print(sp);                                // 5 19 -2

    stack_push(sp, 27);
    stack_print(sp);                                // 5 19 -2 27

    printf("is_empty=%d\n", stack_is_empty(sp));    // is_empty=0
    printf("size=%d\n", stack_size(sp));            // size=4

    Data x = stack_pop(sp);
    printf("x=%d\n", x);                            // x=27

    x = stack_pop(sp);
    printf("x=%d\n", x);                            // x=-2

    stack_print(sp);                                // 5 19

    while (!stack_is_empty(sp)) {
        x = stack_pop(sp);
        printf("x=%d\n", x);
        stack_print(sp);
    }
                                                    // x=19
                                                    // 5
                                                    // x=5
                                                    // пустая строка
    
    if (NULL == stack_destroy(sp))
        printf("end\n");                            // end
}


int main() {
    test0();

    return 0;
}
