#include <stdio.h>
#include "geometry.h"


int is_crossed(struct Rect a, struct Rect b);
struct Rect intersection(struct Rect a, struct Rect b);


int main() {
    struct Rect a;
    struct Rect b;
    scanf("%d %d %d %d", &a.lt.x, &a.lt.y, &a.rb.x, &a.rb.y);
    scanf("%d %d %d %d", &b.lt.x, &b.lt.y, &b.rb.x, &b.rb.y);

    if (is_crossed(a, b)) {
        struct Rect result = intersection(a, b);
        printf("%d %d %d %d\n", result.lt.x, result.lt.y, result.rb.x, result.rb.y);
    }

    return 0;
}
