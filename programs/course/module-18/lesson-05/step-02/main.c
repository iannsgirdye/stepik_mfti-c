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


// тестовая функция из условия
void test() {
    struct Node * tree=NULL;
    tree = tree_add(tree, 7);
    tree = tree_add(tree, 3);
    tree = tree_add(tree, 2);
    tree = tree_add(tree, 1);
    tree = tree_add(tree, 9);
    tree = tree_add(tree, 5);
    tree = tree_add(tree, 4);
    tree = tree_add(tree, 6);
    tree = tree_add(tree, 8);
    tree_print(tree);  // напечатает 1 2 3 4 5 6 7 8 9
    printf("\n");      // добавил я
}


int main() {
    test();

    return 0;
}
