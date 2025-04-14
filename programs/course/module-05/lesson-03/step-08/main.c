struct Rect {
    int x;      // х координата левой верхней вершины
    int y;      // y координата левой верхней вершины
    int width;  // ширина
    int height; // высота
};

int area(struct Rect a)
{
    return a.width * a.height;
}
