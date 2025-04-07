// Очередь на основе динамического массива

#ifndef QUEUE_H
#define QUEUE_H


#include <stdlib.h>


#define UPGRADE_VALUE 2


typedef int Data;
typedef struct {
    int start;    // индекс начала
    int end;      // индекс конца
    int count;    // количество
    size_t size;  // размер
    Data a[1];    // данные
} Queue;


// Создать очередь
Queue *create(size_t size) {
    Queue *queue = (Queue *)malloc(2 * sizeof(int) + sizeof(size_t) + sizeof(Data));
    if (queue = NULL) {
        printf("Error: malloc() in create()");
        exit(1);
    }

    queue->start = 0;
    queue->end = 0;
    queue->size = size;
    
    return queue;
}


// Удалить очередь
Queue *delete(Queue *queue) {
    free(queue);
    return NULL;
}


// Увеличить размер массива данных в UPGRADE_VALUE раз
Queue *upgrade(Queue *queue) {
    Queue *new_queue = realloc(queue, queue->size * UPGRADE_VALUE);
    if (new_queue == NULL) {  // завершение программы в случае неудачного выделения
        printf("Error: realloc() in upgrade()");
        exit(1);
    }
    
    return new_queue;
}


// Если очередь пустая, вернуть 1, иначе вернуть 0
int is_empty(Queue *queue) {
    return (queue->count == 0)? 1 : 0;
}


// Если очередь полная, вернуть 1, иначе вернуть 0
int is_full(Queue *queue) {
    return (queue->count == queue->size)? 1 : 0;
}


// Добавить элемент в очередь
Queue *enqueue(Data element, Queue *queue) {
    if (is_full(queue) == 1) {
        queue = upgrade(queue);
    }

    if (queue->end)
}


// Убрать элемент из очереди и вернуть его
Data dequeue(Queue *queue) {
    if (is_empty(queue) == 0) {

    }

    Data element;

    return element;
}


#endif  // QUEUE_H
