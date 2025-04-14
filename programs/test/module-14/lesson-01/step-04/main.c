#include <stdio.h>
#include <stdlib.h>


int main() {
    // int n;
    // scanf("%d", &n);

    // int *a = malloc(n * sizeof(int));   
    // free(a);

    int a[9] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    if (a[0] == *a && a[0] == *(a + 0) && 0[a] == a[0]) {
        printf("YES\n");
    }

    int x = 10;
    int y = 20;
    int *px = &x;
    int *py = &y;

    printf("%d | %d | %d | %d | %d\n", px[2], *px, *(px + 1), px[0], px[1]);

    return 0;
}
