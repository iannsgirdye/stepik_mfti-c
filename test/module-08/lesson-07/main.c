// module8 -> lesson7
// Адресная арифметика

#include <stdio.h>


int main() {
    short int x = 10;
    short int y = 20;
    short int *px = &x;
    short int *px2 = px + 1;
    short int *py = &y;



    long long int z = 30;
    long long int *pz = &z;
    long long int w = 40;
    long long int *pw = &w;
    long long int *pw2 = pw + 1;

    long long int *random_data = pw2 + 1;

    int a[10];
    int b[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    int c[5][5];
    int d[4][4] = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34},
        {41, 42, 43, 44}
    };

    printf(">  px = %p |  px2 = %p |  py = %p \n", px, px2, py);
    printf("> *px = %-14hd | *px2 = %-14hd | *py = %-14hd\n", *px, *px2, *py);
    printf("> px2 - px = %ld | *random_data = %lld\n\n", px2 - px, *random_data);

    printf(">  pw = %p |  pw2 = %p |  pz = %p \n", pw, pw2, pz);
    printf("> *pz = %-14lld | *pz2 = %-14lld | *pw = %-14lld\n", *pw, *pw2, *pz);
    printf("> pw2 - pw = %ld\n", pw2 - pw);

    

    return 0;
}
