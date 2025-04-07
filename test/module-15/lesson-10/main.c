#include <stdlib.h>


typedef int Data;

typedef struct {
    unsigned n;   // количество элементов
    size_t size;  // количество выделенных ячеек в массиве
    Data a[1];    // массив (a[0] - единственный "настоящий" элемент)
} Stack;


/* Так как место в памяти для стека будет выделяться через malloc() и при необходимости изменяться через realloc(), 
   то есть будет динамической, то можно будет обращаться к ненастоящей i-й ячейке массива через a[i].          
   Нужно будет контролировать, что при обращении к i-й ячейке массива i < size, 
   иначе будет обращение к неиницилизированной памяти (за рамками того, сколько всего выделил malloc() или realloc()). */
