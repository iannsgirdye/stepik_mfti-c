#include <stdio.h>
#include <stdlib.h>


#define max(a, b) (a > b)? a : b
#define min(a, b) (a < b)? a : b
#define MIN_NUM 0
#define MAX_NUM 1000000


typedef int Data;
struct Node {
    Data val;            // данные
    struct Node *left;   // левый ребёнок
    struct Node *right;  // правый ребёнок
};
struct QueueNode {
    struct Node *tree;       // корень (под)дерева
    struct QueueNode *next;  // следующий узел очереди (корень другого (под)дерева)
};
struct Queue {
    struct QueueNode *first;  // первый узел
    struct QueueNode *last;   // последний узел
};


// проверка очереди на пустоту
int queue_is_empty(struct Queue *queue) {
    return (queue->first == NULL)? 1 : 0;
}


// добавление элемента [x] в конец очереди
void queue_enqueue(struct Queue *queue, struct Node *tree) {
    struct QueueNode *last_tree = malloc(sizeof(struct QueueNode));
    last_tree->tree = tree;         // значение нового последнего
    last_tree->next = NULL;         // у нового последнего нет следующего
    if (queue_is_empty(queue)) {
        queue->first = last_tree;   // новый последний будет новым первым, если очередь пустая
    }
    else {
        queue->last->next = last_tree;  // у текущего последнего теперь новый следующий
    }
    queue->last = last_tree;        // в очереди новый последний
}


// возврат и удаление элемента [x] из начала очереди
struct Node *queue_dequeue(struct Queue *queue) {
    if (queue_is_empty(queue)) {
        printf("Error: queue_dequeue()\n");
        exit(EXIT_FAILURE);
    }

    struct Node *tree = queue->first->tree;
    struct QueueNode *queuenode_to_free = queue->first;
    queue->first = queue->first->next;
    free(queuenode_to_free);
    return tree;
}


// печать элементов очереди через пробел
void queue_print(struct Queue *queue) {
    for (struct QueueNode *queuenode = queue->first; queuenode!= NULL; queuenode = queuenode->next) {
        printf("%d ", queuenode->tree->val);
    }
    printf("\n");
}


// инициализация узла дерева со значением [x]
struct Node *tree_init(Data x) {
    struct Node *leaf = malloc(sizeof(struct Node));
    leaf->val = x;
    leaf->left = NULL;
    leaf->right = NULL;
    return leaf;
}


// добавление узла со значением [x]
struct Node *tree_add(struct Node *tree, Data x) {
    if (tree == NULL) {
        return tree_init(x);
    }
    
    if (x < tree->val) {
        tree->left = tree_add(tree->left, x);
    }
    else if (x > tree->val) {
        tree->right = tree_add(tree->right, x);
    }

    return tree;
}


// обход дерева в глубину слева направо, печатая значения узлов через пробел
void tree_print_depth(struct Node *tree) {
    if (tree == NULL) {
        return;
    }

    tree_print_depth(tree->left);
    printf("%d ", tree->val);
    tree_print_depth(tree->right);
}


// освобождение динамической памяти, использованной для хранения узла tree и его детей
void tree_destroy(struct Node *tree) {
    if (tree->left != NULL) {
        tree_destroy(tree->left);
    }
    if (tree->right != NULL) {
        tree_destroy(tree->right);
    }
    free(tree);
}


// обход дерева в глубину слева направо, печатая значения листьев
void tree_print_leafs(struct Node *tree) {
    if (tree->left != NULL) {
        tree_print_leafs(tree->left);
    }
    if (tree->right != NULL) {
        tree_print_leafs(tree->right);
    }
    if (tree->left == NULL && tree->right == NULL) {
        printf("%d ", tree->val);
    }
}


// проверка дерева на пустоту
int tree_is_empty(struct Node *tree) {
    return (tree == NULL)? 1 : 0;
}


// вычисление глубины дерева
void tree_depth(struct Node *tree, int *total_depth, int depth) {
    if (tree_is_empty(tree)) {
        *total_depth = 0;
        return;
    }
    if (tree->left != NULL) {
        tree_depth(tree->left, total_depth, depth + 1);
    }
    if (tree->right != NULL) {
        tree_depth(tree->right, total_depth, depth + 1);
    }
    *total_depth = max(*total_depth, depth);
}


// проверка балансировки дерева
void tree_check_balance(int *result, struct Node *tree) {
    if (tree_is_empty(tree)) {
        return;
    }

    int left_depth = 1, right_depth = 1;
    tree_depth(tree->left, &left_depth, 1);
    tree_depth(tree->right, &right_depth, 1);

    if (abs(left_depth - right_depth) > 1) {
        *result = 0;
        return;
    }

    tree_check_balance(result, tree->left);
    tree_check_balance(result, tree->right);
}


// печать значений узлов на уровне N (у корня уровень 0)
void tree_search(struct Node *tree, int level, int N) {
    if (tree == NULL) {
        return;
    }
    
    if (level == N) {
        printf("%d ", tree->val);
        return;
    }
    
    tree_search(tree->left, level + 1, N);
    tree_search(tree->right, level + 1, N);
}


// считывание дерева
void tree_scan(struct Node **tree) {
    Data x;
    scanf("%d", &x);

    while (x != 0) {
        *tree = tree_add(*tree, x);
        scanf("%d", &x);
    }
}


// обход дерева в ширину, печатая значения узлов
void tree_print_width(struct Queue *queue) {
    while (queue_is_empty(queue) == 0) {
        struct Node *tree = queue_dequeue(queue);
        printf("%d ", tree->val);
        if (tree->left != NULL) {
            queue_enqueue(queue, tree->left);
        }
        if (tree->right != NULL) {
            queue_enqueue(queue, tree->right);
        }
        tree_print_width(queue);
    }
}


int main() {
    struct Node *tree = NULL;           // дерево (указатель на root)
    tree_scan(&tree);
    
    int N;                              // нужный уровень
    scanf("%d", &N);

    struct Queue queue = {NULL, NULL};  // очередь для обхода дерева в ширину
    queue_enqueue(&queue, tree);
    tree_print_width(&queue);
    printf("\n");

    tree_destroy(tree);

    return 0;
}
