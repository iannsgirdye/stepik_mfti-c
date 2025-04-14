// struct Point {
//     int x;
//     int y;
// };

// struct Rect {
//     struct Point lt;    // координаты левой верхней вершины
//     struct Point rb;    // координаты правой нижней вершины
// };

int area(struct Rect a)
{
    int width = a.rb.x - a.lt.x;   // x_right - x_left
    int height = a.lt.y - a.rb.y;  // y_left  - x_right
    return width * height;         // площадь
}