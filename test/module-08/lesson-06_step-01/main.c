#include <stdio.h>

int main() {
    int x = 10;
    printf("%d %zu", typeof(sizeof(x)), sizeof(x));
    
    return 0;
}
