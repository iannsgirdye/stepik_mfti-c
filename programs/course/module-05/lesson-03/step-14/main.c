// struct Rect {
//     int x;      // х координата левой верхней вершины
//     int y;      // y координата левой верхней вершины
//     int width;  // ширина
//     int height; // высота
// };

// void move(struct Rect * p, int dx);

void move(struct Rect * p, int dx)
{
    p->x += dx;
}
