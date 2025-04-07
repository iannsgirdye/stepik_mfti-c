#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 3  // количество строк
#define N 5  // количество столбцов

void read_matrix(int matrix[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void create_matrix(int ***matrix) {
    *matrix = malloc(M * sizeof(int *) + M * N * sizeof(int));  // память под массив указателей + данные
    int *start_matrix = (int *)(*matrix + M);                   // начало массива данных
    for (int i = 0; i < M; i++) {                               // установка указателей на строки
        (*matrix)[i] = start_matrix + i * N;
    }    
}

void print_matrix(int **matrix) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix1[M][N];
    read_matrix(matrix1);
    
    int **matrix2 = NULL;
    create_matrix(&matrix2);
    
    memcpy(matrix2[0], matrix1, M * N * sizeof(int));
    
    print_matrix(matrix2);

    free(matrix2);
    matrix2 = NULL;
    return 0;
}
