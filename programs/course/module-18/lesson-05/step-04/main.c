#include <stdio.h>
#include <stdlib.h>


typedef int Data;
struct Node {
    Data val;            // данные
    struct Node *left;   // левый ребёнок
    struct Node *right;  // правый ребёнок
};


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


int main() {
    Data x;
    scanf("%d", &x);
    struct Node *tree = NULL;

    while (x != 0) {
        tree = tree_add(tree, x);
        scanf("%d", &x);
    }
    
    tree_print(tree);
    printf("\n");
    tree_destroy(tree);
    
    return 0;
}
