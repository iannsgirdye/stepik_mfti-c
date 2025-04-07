#include <stdio.h>

int main() {
    int letter1, letter2;
    
    printf("Enter 2 letters like AB: ");
    letter1 = getchar();
    letter2 = getchar();
    
    printf("letter1 is ");
    putchar(letter1);
    printf(" and letter2 is ");
    putchar(letter2);
    printf("\n");
    
    return 0;
}
