#include <stdio.h>
#include <stdlib.h>


#define min(a, b) ((a < b)? a : b)
#define max(a, b) ((a > b)? a : b)


typedef unsigned long long int llu;
typedef struct {
    char *a;            // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;     // наибольшая степень десяти
    unsigned int size;  // размер выделенной динамической памяти в а
} Decimal;


void elong_add(const Decimal * a, const Decimal * b, Decimal * res) {
    int additional = 0;       // единица при переполнении
    int sum = 0;              // текущая сумма разрядов

    res->n = 0;
    res->size = max(a->size, b->size);
    res->a = malloc(res->size);

    for ( ; res->n <= min(a->n, b->n); (res->n)++) {
        sum = (a->a)[res->n] + (b->a)[res->n] + additional;
        (res->a)[res->n] = sum % 10;
        additional = sum / 10;
    }

    if (a->n > b->n) {
        for ( ; res->n <= a->n; (res->n)++) {
            sum = (a->a)[res->n] + additional;
            (res->a)[res->n] = sum % 10;
            additional = sum / 10;
        }
    }
    else if (a->n < b->n) {
        for ( ; res->n <= b->n; (res->n)++) {
            sum = (b->a)[res->n] + additional;
            (res->a)[res->n] = sum % 10;
            additional = sum / 10;
        }
    }
    (res->n)--;

    if (additional == 1) {
        (res->n)++;
        res->a = realloc(res->a, res->size + 1);
        (res->a)[res->n] += additional;
    }
}


void elong_set_int(Decimal * px, llu number)
{
    if (number == 0) {       // 0 * 10^0
        px->size = 1;
        px->n = 0;
        px->a = malloc(px->size);
        px->a[0] = 0;
        return;
    }

    // number точно меньше 10 в 100, выделим память с запасом
    px->size = 100;
    px->a = malloc(px->size);

    for (px->n = 0; number > 0; px->n++) {
        px->a[px->n] = number % 10;
        number /= 10;
    }
    px->n --;

    // выделим памяти точно под хранение числа
    px->size = px->n + 1;
    px->a = realloc(px->a, px->size);
}


void elong_destroy(Decimal * px)
{
    free(px->a);  // освобождаем желтый массив с цифрами
}


void elong_print(Decimal x) 
{
    for (int i = x.n; i >= 0; i--) {
        printf("%d", x.a[i]);
    }
    printf("\n");
}


int main(){
    Decimal a;
    Decimal b;
    Decimal res;

    llu number_a, number_b;
    scanf("%llu%llu", &number_a, &number_b);

    elong_set_int(&a, number_a);   // 1-е число из llu в Decimal
    elong_set_int(&b, number_b);   // 2-е число из llu в Decimal

    elong_add(&a, &b, &res);       // сумма

    elong_print(res);              // вывод суммы

    elong_destroy(&a);
    elong_destroy(&b);
    elong_destroy(&res);

    return 0;
}
