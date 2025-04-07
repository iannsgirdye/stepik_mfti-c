#include <stdio.h>


typedef struct {
    char * a;           // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;     // наибольшая степень десяти
    unsigned int size;  // размер выделенной динамической памяти в а
} Decimal;





int main(){
    Decimal a;
    Decimal b;
    Decimal res;

    elong_set_int(&a, 147);    // 147
    elong_set_int(&b, 13);     // 13

    elong_add(&a, &b, &res);   // res = a+b = 147+13 = 160

    elong_print(res);          // print 160

    elong_destroy(&a);
    elong_destroy(&b);
    elong_destroy(&res);

    return 0;
}
