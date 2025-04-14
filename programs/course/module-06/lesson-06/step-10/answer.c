#define min(a, b) ((a < b)? a : b)
#define max(a, b) ((a > b)? a : b)


void check_points(struct Point * one, struct Point * two, struct Point * general, int * found) {
    (*found)++;
    if (one->x == 0 && one->y == 0) {              // даже если была найдена точка (0; 0) 
        one->x = general->x, one->y = general->y;  // она будет храниться в two
    }
    else {
        two->x = general->x, two->y = general->y;
    }
}


struct Rect intersection(struct Rect a, struct Rect b) {
    struct Point one = {0, 0};
    struct Point two = {0, 0};
    int found = 0;              //  счётчик найденных точек;

    // 1. верхняя левая точка b внутри a
    if (a.lt.x <= b.lt.x && b.lt.x <= a.rb.x && a.lt.y >= b.lt.y && b.lt.y >= a.rb.y) {
        struct Point general = {b.lt.x, b.lt.y};
        check_points(&one, &two, &general, &found);
    }

    // 2. нижняя левая точка b внутри a
    if (a.lt.x <= b.lt.x && b.lt.x <= a.rb.x && a.lt.y >= b.rb.y && b.rb.y >= a.rb.y) {
        struct Point general = {b.lt.x, b.rb.y};
        check_points(&one, &two, &general, &found);
    }
    
    // 3. верхняя правая точка b внутри a
    if (a.lt.x <= b.rb.x && b.rb.x <= a.rb.x && a.lt.y >= b.lt.y && b.lt.y >= a.rb.y) {
        struct Point general = {b.rb.x, b.lt.y};
        check_points(&one, &two, &general, &found);
    }

    // 4. нижняя правая точка b внутри a
    if (a.lt.x <= b.rb.x && b.rb.x <= a.rb.x && a.lt.y >= b.rb.y && b.rb.y >= a.rb.y) {
        struct Point general = {b.rb.x, b.rb.y};
        check_points(&one, &two, &general, &found);
    }

    // Если b полностью в a
    if (found > 2) {
        struct Rect new = {{max(a.lt.x, b.lt.x), min(a.lt.y, b.lt.y)}, {min(a.rb.x, b.rb.x), max(a.rb.y, b.rb.y)}};
        return new;
    }

    // Если только 2 точки b в a
        if (one.x == two.x) {
            if (one.x == b.lt.x) {
                struct Rect new = {{b.lt.x, b.lt.y}, {a.rb.x, b.rb.y}};
                return new;
            }
            else if (one.x == b.rb.x) {
                struct Rect new = {{a.lt.x, b.lt.y}, {b.rb.x, b.rb.y}};
                return new;
            }       
        }
        else if (one.y == two.y) {
            if (one.y == b.lt.y) {
                struct Rect new = {{b.lt.x, b.lt.y}, {b.rb.x, a.rb.y}};
                return new;
            }
            else if (one.x == b.rb.x) {
                struct Rect new = {{b.lt.x, a.lt.y}, {b.rb.x, b.rb.y}};
                return new;
            }     
        }

    // 5. верхняя левая точка a внутри b
    if (b.lt.x <= a.lt.x && a.lt.x <= b.rb.x && b.lt.y >= a.lt.y && a.lt.y >= b.rb.y) {
        struct Point general = {a.lt.x, a.lt.y};
        check_points(&one, &two, &general, &found);
    }

    // 6. нижняя левая точка a внутри b
    if (b.lt.x <= a.lt.x && a.lt.x <= b.rb.x && b.lt.y >= a.rb.y && a.rb.y >= b.rb.y) {
        struct Point general = {a.lt.x, a.rb.y};
        check_points(&one, &two, &general, &found);
    }
    
    // 7. верхняя правая точка a внутри b
    if (b.lt.x <= a.rb.x && a.rb.x <= b.rb.x && b.lt.y >= a.lt.y && a.lt.y >= b.rb.y) {
        struct Point general = {a.rb.x, a.lt.y};
        check_points(&one, &two, &general, &found);
    }

    // 8. нижняя правая точка a внутри b
    if (b.lt.x <= a.rb.x && a.rb.x <= b.rb.x && b.lt.y >= a.rb.y && a.rb.y >= b.rb.y) {
        struct Point general = {a.rb.x, a.rb.y};
        check_points(&one, &two, &general, &found);
    }

    // Если a полностью в b
    if (found > 2) {
        struct Rect new = {{max(a.lt.x, b.lt.x), min(a.lt.y, b.lt.y)}, {min(a.rb.x, b.rb.x), max(a.rb.y, b.rb.y)}};
        return new;
    }

    // Если у прямоугольников по 1 точке друг в друге
    if (one.x != two.x && one.y != two.y) {  
        struct Rect new = {{min(one.x, two.x), max(one.y, two.y)}, {max(one.x, two.x), min(one.y, two.y)}};
        return new;
    }

    // Если только 2 точки a в b
    if (one.x == two.x) {
        if (one.x == a.lt.x) {
            struct Rect new = {{a.lt.x, a.lt.y}, {b.rb.x, a.rb.y}};
            return new;
        }
        else if (one.x == a.rb.x) {
            struct Rect new = {{b.lt.x, a.lt.y}, {a.rb.x, a.rb.y}};
            return new;
        }       
    }
    else if (one.y == two.y) {
        if (one.y == a.lt.y) {
            struct Rect new = {{a.lt.x, a.lt.y}, {a.rb.x, b.rb.y}};
            return new;
        }
        else if (one.x == a.rb.x) {
            struct Rect new = {{a.lt.x, b.lt.y}, {a.rb.x, a.rb.y}};
            return new;
        }     
    }
}