#include <stdlib.h>


int main() {
    int * a = malloc(10 * sizeof(int));
    free(a);   // взять за привычку после освобождения динамической памяти
    a = NULL;  // обнулять указатель, чтобы следующий free(a) не выдал ошибку
}
