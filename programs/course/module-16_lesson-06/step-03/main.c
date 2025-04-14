#include <stdio.h>
#include <stdlib.h>


typedef int Data;
struct Node {
    Data val;           // данные в этом узле
    struct Node *next;  // указатель на следующий узел списка
};


struct Node *list_create();
void list_push(struct Node **plist, Data x);
Data list_pop(struct Node **plist);
Data list_get(struct Node *list);
void list_print(struct Node *list);
int  list_size(struct Node *list);
int  list_is_empty(struct Node *list);
void list_clear(struct Node **plist);


// создать список
struct Node *list_create() {
    return NULL;
}


// добавить элемент на вершину
void list_push(struct Node **plist, Data x) {
    struct Node *node = malloc(sizeof(struct Node));  // выделить память для нового узла
    node->val = x;                                    // добавить в новый узел элемент
    node->next = (*plist);                            // добавить в новый узел указатель на прошлую вершину
    *plist = node;                                    // изменить вершину на новую
}


// достать элемент вершины и вернуть его
Data list_pop(struct Node **plist) {
    if (list_is_empty(*plist) == 0) {
        struct Node *node = (*plist);  // текущая вершина
        Data x = (*plist)->val;        // элемент вершины
        *plist = node->next;           // новая вершина
        free(node);                    // освобождение места для бывшей вершины
        return x;
    }
    exit(1);
}


// вернуть элемент на вершине
Data list_get(struct Node *list) {
    return list->val;
}


// вывести элементы списка через пробел
void list_print(struct Node *list) {
    for (struct Node *node = list; node != NULL; node = node->next) {
        printf("%d ", node->val);
    }
    printf("\n");
}


// вернуть количество элементов в списке
int list_size(struct Node *list) {
    int size = 0;
    for (struct Node *node = list; node != NULL; node = node->next) {
        size++;
    }
    return size;
}


// вернуть 1, если список пустой, иначе вернуть 0
int list_is_empty(struct Node *list) {
    return (list == NULL)? 1 : 0;
}



// очистить список, освободив память
void list_clear(struct Node **plist) {
    struct Node *node = *plist;
    while (node != NULL) {
        struct Node *next_node = node->next;
        free(node);
        node = next_node;
    }
    *plist = NULL;
}


void test0() {
    struct Node *list = list_create();
    list_print(list);                               // пустая строка
    printf("is_empty = %d\n", list_is_empty(list)); // is_empty = 1
    printf("size = %d\n", list_size(list));         // size = 0

    list_push(&list, 21);
    list_print(list);                               // 21
    list_push(&list, 17);
    list_print(list);                               // 17 21
    list_push(&list, 3);
    list_print(list);                               // 3 17 21
    printf("is_empty = %d\n", list_is_empty(list)); // is_empty = 0
    printf("size = %d\n", list_size(list));         // size = 3

    Data x = list_pop(&list);
    printf("pop %d\n", x);                          // pop 3
    list_print(list);                               // 17 21
    printf("size = %d\n", list_size(list));         // size = 2

    list_clear(&list);
    list_print(list);                               // пустая строка
    printf("is_empty = %d\n", list_is_empty(list)); // is_empty = 1
    printf("size = %d\n", list_size(list));         // size = 0
}


int main() {
    test0();

    return 0;
}
