// module3 -> lesson7 -> step11

#include <stdio.h>

int main()
{
    char          a1 = 10;               //  8 бит |    знаковый |        десятичное число
    short int     b1 = 0b1010;           // 16 бит |    знаковый |          двоичное число
    short         c1 = 012;              // 16 бит |    знаковый |      восьмеричное число
    int           d1 = 0xA;              // 32 бит |    знаковый | шестнадцатеричное число
    long int      e1 = 10;               // 32 бит |    знаковый |        десятичное число
    long          f1 = 0b1010;           // 32 бит |    знаковый |          двоичное число
    long long int g1 = 012;              // 64 бит |    знаковый |      восьмеричное число
    long long     h1 = 0xA;              // 64 бит |    знаковый | шестнадцатеричное число

    signed char          a2;             //  8 бит |    знаковый
    signed short int     b2;             // 16 бит |    знаковый
    signed short         c2;             // 16 бит |    знаковый
    signed int           d2;             // 32 бит |    знаковый
    signed long int      e2;             // 32 бит |    знаковый
    signed long          f2;             // 32 бит |    знаковый
    signed long long int g2;             // 64 бит |    знаковый
    signed long long     h2;             // 64 бит |    знаковый

    unsigned char          a3 = 10;      //  8 бит | беззнаковый |        десятичное число
    unsigned short int     b3 = 0b1010;  // 16 бит | беззнаковый |          двоичное число
    unsigned short         c3 = 012;     // 16 бит | беззнаковый |      восьмеричное число
    unsigned int           d3 = 0xA;     // 32 бит | беззнаковый | шестнадцатеричное число
    unsigned long int      e3 = 10;      // 32 бит | беззнаковый |        десятичное число
    unsigned long          f3 = 0b1010;  // 32 бит | беззнаковый |          двоичное число
    unsigned long long int g3 = 012;     // 64 бит | беззнаковый |      восьмеричное число
    unsigned long long     h3 = 0xA;     // 64 бит | беззнаковый | шестнадцатеричное число

    printf("%hhd\n", a1);
    printf("Здесь должно быть двоичное число\n");
    printf("%hho\n", c1);
    printf("%x  \n", d1);
    printf("%ld \n", e1);
    printf("Здесь должно быть двоичное число\n");
    printf("%llo\n", g1);
    printf("%llX\n", h1);
    printf("------------------------------------\n");
    printf("%hhu\n", a3);
    printf("Здесь должно быть двоичное число\n");
    printf("%d  \n", c3);
    printf("%u  \n", d3);
    printf("%lu  \n", e3);
    printf("Здесь должно быть двоичное число\n");
    printf("%llu\n", g3);
    printf("%llu\n", h3);

    return 0;
}
