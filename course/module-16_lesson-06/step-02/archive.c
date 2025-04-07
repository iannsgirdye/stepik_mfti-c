#include <stdio.h>


typedef int Data;

typedef struct Node {
    Data val;           // данные, которые хранятся в одном элементе
    struct Node *next;  // указатель на следующий элемент списка
} Node;
typedef Node *List;


// создать список
List list_create() {
    return NULL; 
}


// очистить список
void list_clear(List *p_list) {
    /* Логика: освобождать память, которую занимает текущий узел и переходить к следующему узлу для 
       его освобождения, пока указатель на следующий узел не станет равен NULL */
    List point = *p_list;
    while (point != NULL) {
        
        point = point->next;

    }
    (*p_list)->next = NULL;
    
}


// положить element на верхушку списка
void list_push(List *p_list, Data element) {
    Node *p_node = malloc(sizeof(Node));
    p_node->val = element;
    p_node->next = (*p_list)->next;
    p_list = p_node;
}


// снять element с верхушки списка и вернуть его
Data list_pop(List *p_list) {
    if (list_is_empty(p_list) == 0) {
        Data element = (*p_list)->val;
        p_list = (*p_list)->next;
        return element;
    }
}


// вернуть element с верхушки списка
Data list_get(List list) {
    return list->val;
}


// вернуть количество элементов в списке
int list_size(List list) {
    p_next = 
    for (int i = 0; list.->)
}


// вернуть 1, если список пустой, иначе вернуть 0
int list_is_empty(List list) {

}


// напечатать все elements списка через пробел 
void list_print(List list) {

}


int main() {
    List list = NULL;

    return 0;
}
