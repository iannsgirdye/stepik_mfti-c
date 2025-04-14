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
void tree_print(struct Node *tree) {
    if (tree == NULL) {
        return;
    }

    tree_print(tree->left);
    printf("%d ", tree->val);
    tree_print(tree->right);
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


int main() {
    Data x;
    scanf("%d", &x);
    struct Node *tree = NULL;

    while (x != 0) {
        tree = tree_add(tree, x);
        scanf("%d", &x);
    }

    if (tree_is_empty(tree)) {
        printf("YES\n");
        tree_destroy(tree);
    }

    int result = 1;
    tree_check_balance(&result, tree);
    switch (result) {
        case 0:
            printf("NO\n");
            break;
        case 1:
            printf("YES\n");
            break;
    }
    tree_destroy(tree);

    return 0;
}
