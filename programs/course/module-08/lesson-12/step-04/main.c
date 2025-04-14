#include <stdio.h>

#define N 100
#define min(a, b) ((a < b)? a : b)
#define max(a, b) ((a > b)? a : b)


typedef struct {
    char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;  // наибольшая степень десяти
} Decimal;


void elong_print(Decimal x) {
    for (int i = x.n; i >= 0; i--) {
        printf("%hhd", x.a[i]);
    }
    printf("\n");
}


Decimal add(Decimal x, Decimal y) {
    Decimal result;
    result.n = max(x.n, y.n);
    char additional = 0;
    char sum;
    
    // Сложение тех разрядов, которые есть у обоих чисел
    for (int i = 0; i <= (min(x.n, y.n)); i++) {
        sum = x.a[i] + y.a[i] + additional;  // пораздрядное сложение
        result.a[i] = sum % 10;              // фиксация результата
        additional = sum / 10;               // единица в случае переполнения (7 + 4 = 11)
    }
    
    // Добавление разрядов большего числа
    if (x.n > y.n) {
        for (int i = y.n + 1; i <= x.n; i++) {
            sum = x.a[i] + additional;
            result.a[i] = sum % 10;
            additional = sum / 10;
        }
    }
    else if (x.n < y.n) {
        for (int i = x.n + 1; i <= y.n; i++) {
            sum = y.a[i] + additional;
            result.a[i] = sum % 10;
            additional = sum / 10;
        }
    }

    if (additional == 1) {  // Если есть переполнение после последнего сложения
        result.a[result.n + 1] = additional;  // перенос единицы
        (result.n)++;                         // увеличение наибольшей степени десяти на 1
    }

    return result;
}


int main(){
    Decimal x = {{7, 4, 1}, 2};  // set number 147
    Decimal y = {{3, 1}, 1};     // set number 13
    Decimal res;

    res = add(x, y);             // res = x + y = 147 + 13 = 160
    elong_print(res);            // print 160

    return 0;
}
