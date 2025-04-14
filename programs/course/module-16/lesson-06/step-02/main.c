#include <stdio.h>
#include <stdlib.h>


typedef int Data;
struct Node {
    Data val;
    struct Node *next;
};
typedef struct Node *List;


List list_create();
void list_push(List *plist, Data x);
Data list_pop(List *plist);
Data list_get(List list);
void list_print(List list);
int  list_size(List list);
int  list_is_empty(List list);
void list_clear(List *plist);


List list_create() {
    return NULL;
}


// добавить число на вершину списка
void list_push(List *plist, Data x) {
    struct Node *pnode = (struct Node *)malloc(sizeof(struct Node));  // выделить память для нового узла
    pnode->val = x;                             // добавить элемент в новый узел
    pnode->next = *plist;                        // добавить в новую вершину указатель на прошлую
    *plist = pnode;                              // сменить вершину на новую
}


// достать число с вершины и вернуть его
Data list_pop(List *plist) {
    if (list_is_empty(*plist) == 0) {
        struct Node *pnode = *plist;     // указатель на текущую вершину
        Data x = (*plist)->val;  // достать элемент вершины
        *plist = (*plist)->next;  // сменить вершину на второй сверху узел
        free(pnode);              // освободить память для прошлой вершины
        return x;
    }
    exit(1);                      // завершить работу программы, если список пустой
}


// вернуть число в вершине
Data list_get(List list) {
    return list->val;
}


// напечать через пробел числа списка
void list_print(List list) {
    struct Node *node = list;
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}


// вернуть количество элементов в списке
int list_size(List list) {
    struct Node *node = list;
    int size = 0;
    while (node != NULL) {
        size++;
        node = node->next;
    }
    return size;
}


// вернуть 1, если списокк пустой, иначе вернуть 0
int list_is_empty(List list) {
    return (list == NULL)? 1 : 0;
}


// опустошить список, освободив память
void list_clear(List *plist) {
    struct Node *node = *plist;
    while (node != NULL) {
        struct Node *node_to_clear = node;  // текущий узел на освобождение
        node = node->next;           // следующий узел на освобождение (NULL, если текущий = последний)
        free(node_to_clear);         // освободить текущий
    }
    *plist = NULL;
}


void test0() {
    List list = list_create();
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
