#include <stdio.h>
#include <stdlib.h>


#define max(a, b) (a > b)? a : b


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


void tree_search(struct Node *tree) {
    if (tree->left != NULL) {
        tree_search(tree->left);
    }
    if (tree->right != NULL) {
        tree_search(tree->right);
    }
    if (tree->left == NULL && tree->right == NULL) {
        printf("%d ", tree->val);
    }
}


void tree_depth(struct Node *tree, int *total_depth, int depth) {
    if (tree == NULL) {
        *total_depth = 0;
        return;
    }
    if (tree->left != NULL) {
        tree_depth(tree->left, total_depth, depth + 1);
    }
    if (tree->right != NULL) {
        tree_depth(tree->right, total_depth, depth + 1);
    }
    *total_depth = max(*total_depth, depth) + 1;
}


int main() {
    Data x;
    scanf("%d", &x);
    struct Node *tree = NULL;

    while (x != 0) {
        tree = tree_add(tree, x);
        scanf("%d", &x);
    }
    
    int total_depth = 0;
    tree_depth(tree, &total_depth, 0);
    printf("%d\n", total_depth);
    tree_destroy(tree);
    
    return 0;
}
