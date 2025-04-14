#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int Data;
struct Node {
    struct Node *prev;  // указатель на предыдущий узел
    struct Node *next;  // указатель на следующий узел
    Data data;          // хранящиеся данные
};


void list_init(struct Node *list);
void list_insert(struct Node *list, struct Node *new);
void list_insert_before(struct Node * list, struct Node *new);
void list_remove(struct Node *old);
struct Node *list_push_front(struct Node *list, Data data);
struct Node *list_push_back(struct Node *list, Data data);
Data list_pop_front(struct Node *list);
Data list_pop_back(struct Node *list);
Data list_delete(struct Node *old);
void list_print(struct Node *list);
int  list_is_empty(struct Node *list);
void list_clear(struct Node *list);


// инициализировать пустой список
void list_init(struct Node *list) {
    list->prev = list;
    list->next = list;
    list->data = 0;
}


// вставить элемент new после элемента list
void list_insert(struct Node *list, struct Node *new) {
    new->prev = list;        // было: [list]<->[list->next]; стало: [list]<->[new]<->[list->next]
    new->next = list->next;
    list->next->prev = new;
    list->next = new;
}


// вставить элемент new перед элементом list
void list_insert_before(struct Node *list, struct Node *new) {
    list_insert(list->prev, new);  // [list]...[list->prev][new]
}


// удалить элемент old из списка
void list_remove(struct Node *old) {
    old->prev->next = old->next;  // было: [a]<->[old]<->[b]; стало: [a]<->[b]
    old->next->prev = old->prev;
}


/* 1) выделить память под новый элемент, содержащий данные data
   2) вставить его в голову списка
   3) вернуть указатель на новый элемент или NULL, если произошла ошибка */
struct Node *list_push_front(struct Node *list, Data data) {
    struct Node *new = malloc(sizeof(struct Node));
    if (new == NULL) {
        return NULL;
    }
    new->data = data;
    list_insert(list, new);
    return new;
}


/* 1) выделить память под новый элемент, содержащий данные data
   2) вставить его в хвост списка
   3) вернуть указатель на новый элемент или NULL, если произошла ошибка */
struct Node *list_push_back(struct Node *list, Data data) {
    return list_push_front(list->prev, data);  // [list]...[list->prev][new]
}


// удалить голову списка и вернуть данные из удаленного узла
Data list_pop_front(struct Node *list) {
    return list_delete(list->next);
}


// удалить хвост списка и вернуть данные из удаленного узла
Data list_pop_back(struct Node *list) {
    return list_delete(list->prev);
}


/* 1) удалить узел old из списка
   2) вернуть данные из удаленного узла
   3) освободить память */
Data list_delete(struct Node *old) {
    Data data = old->data;
    list_remove(old);
    free(old);
    return data;
}


// очистить список и освободить память (после этого можно опять добавлять элементы в список)
void list_clear(struct Node *list) {
    while (list_is_empty(list) == 0) {
        struct Node *old = list->next;
        list_remove(old);
        free(old);
    }
}


// вывести через пробел все числа списка (в конце перевод строки)
void list_print(struct Node *list) {
    for (struct Node *current = list->next; current != list; current = current->next) {
        printf("%d ", current->data);
    }
    printf("\n");
}


// вернуть 1, если список пустой, иначе вернуть 0
int list_is_empty(struct Node *list) {
    return (list->next == list)? 1 : 0;
}


// тестовая функция из условия
void test_non_alloc(int n) {
    struct Node *x = malloc(11 * sizeof(struct Node));
    struct Node *a = x + 10;

    list_init(a);
    assert(list_is_empty(a));
    if (n == 1) {
        goto END;
    }

    for (int i = 0; i < 10; i++) {
        x[i].data = i;
        list_insert(a, &x[i]);
    }
    list_print(a);              // 9 8 7 6 5 4 3 2 1 0
    assert(!list_is_empty(a));
    if (n == 2) {
        goto END;
    }

    list_remove(&x[5]);
    list_print(a);              // 9 8 7 6 4 3 2 1 0
    list_remove(&x[0]);
    list_print(a);              // 9 8 7 6 4 3 2 1
    list_remove(&x[9]);
    list_print(a);              // 8 7 6 4 3 2 1
    if (n == 3) {
        goto END;
    }

    list_insert_before(a, &x[0]);
    list_print(a);              // 8 7 6 4 3 2 1 0
    list_insert(a, &x[9]);
    list_print(a);              // 9 8 7 6 4 3 2 1 0
    list_insert(&x[6], &x[5]);
    list_print(a);              // 9 8 7 6 5 4 3 2 1 0
    if (n == 4) {
        goto END;
    }

    while (!list_is_empty(a)) {
        list_remove(a->next);
    }
    if (n == 5) {
        goto END;
    }

END:
    free(x);
}


// тестовая функция из условия
void test_alloc(int n) {
    struct Node a0, b0;
    struct Node *a = &a0;
    struct Node *b = &b0;

    list_init(a);
    list_init(b);

    int i;
    for (i = 0; i < 10; i++) {
        list_push_back(a, i);
    }
    list_print(a);              // 0 1 2 3 4 5 6 7 8 9
    assert(list_is_empty(b));
    if (n == 6) {
        goto END;
    }

    for (i = 0; i < 10; i++) {
        list_push_front(b, list_pop_back(a));
    }
    list_print(b);              // 0 1 2 3 4 5 6 7 8 9
    assert(list_is_empty(a));
    if (n == 7) {
        goto END;
    }

    for (i = 0; i < 10; i++) {
        list_push_front(a, i);
        list_pop_front(b);
    }
    list_print(a);              // 9 8 7 6 5 4 3 2 1 0
    assert(list_is_empty(b));
    if (n == 8) {
        goto END;
    }

    for (i = 0; i < 10; i++) {
        list_push_back(b, list_pop_front(a));
    }
    list_print(b);              // 9 8 7 6 5 4 3 2 1 0
    assert(list_is_empty(a));
    if (n == 9) {
        goto END;
    }

END:
    list_clear(a);
    list_clear(b);
}


int main() {
    test_non_alloc(20);
    test_alloc(20);

    return 0;
}
