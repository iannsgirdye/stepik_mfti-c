// struct Point {
//     int x;
//     int y;
// };
// struct Rect {
//     struct Point lt;    // координаты левой верхней вершины
//     struct Point rb;    // координаты правой нижней вершины
// };

// void move(struct Rect * p, int dx);

void move(struct Rect * p, int dx)
{
    p->lt.x += dx;
    p->rb.x += dx;
}
