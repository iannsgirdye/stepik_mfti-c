#include <stdio.h>


void print_string(char * a) {
    printf("<");
    for (int i = 0; a[i] != '\0'; i++) {
        printf("%c", a[i]);
    }
    printf(">\n");
}


void print_elements(char * a) {
    printf("0-й | %c\n", *a);
    printf("1-й | %c\n", *(a + 1));
    printf("2-й | %c\n", a[2]);
    printf("\n");
}


int main() {
    char a[13] = {0};
    char b[] = {0};
    char c[5] = {'m', 'a', 'n', 'a', '\0'};
    char d[] = {'i', 'd', 'i', ' ', 'n', 'a', 'h', '\0'};
    char e[6] = "Hello";
    char f[] = " , world!";
    char * g = "MAI";

    print_string(c);
    print_string(d);
    print_string(e);
    print_string(f);
    print_string(g);
    printf("\n");
    print_elements(a);  // '\0' '\0' '\0' 
    print_elements(b);  // '\0' и ['m' 'a'] от char c[5]
    print_elements(c);
    print_elements(d);
    print_elements(e);
    print_elements(f);
    print_elements(g);

    return 0;
}
