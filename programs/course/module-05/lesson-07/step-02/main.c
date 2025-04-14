#include <stdio.h>
#include <math.h>


typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point a;      // начало отрезка
    Point b;      // конец отрезка
    float len;    // длина отрезка
} Line;


float distance(Point a, Point b);  // расстояние между точками
void scanLine(Line * t);           // считывание информации о линии
void printLine(Line t);            // печать информации о линии
void rotRLine(Line * t);           // поворот линии


int main() {
    Line t;

    scanLine(&t);
    t.len = distance(t.a, t.b);
    rotRLine(&t);
    printLine(t);

    return 0;
}


float distance(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a. y - b.y));  // теорема Пифагора
}

void scanLine(Line * t)
{
    scanf("%d%d%d%d", &t->a.x, &t->a.y, &t->b.x, &t->b.y);
}

void printLine(Line t)
{
    printf("%d %d %d %d %.3f\n", t.a.x, t.a.y, t.b.x, t.b.y, t.len);
}

void rotRLine(Line * t)
{
    int new_a_x = t->a.y,
        new_a_y = -1 * t->a.x,
        new_b_x = t->b.y,
        new_b_y = -1 * t->b.x; 
    t->a.x = new_a_x;
    t->a.y = new_a_y;
    t->b.x = new_b_x;
    t->b.y = new_b_y;
}
