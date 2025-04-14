struct Point {
    int x;
    int y;
};
struct Rect {
    struct Point lt; // левая верхняя вершина
    struct Point rb; // правая нижняя вершина
};

int is_crossed(struct Rect a, struct Rect b)
{
    if(a.lt.x <= b.lt.x && b.lt.x <= a.rb.x && a.rb.y <= b.lt.y && b.lt.y <= a.lt.y)
        return 1;
    if(a.lt.x <= b.lt.x && b.lt.x <= a.rb.x && a.rb.y <= b.rb.y && b.rb.y <= a.lt.y)
        return 1;
    if(a.lt.x <= b.rb.x && b.rb.x <= a.rb.x && a.rb.y <= b.lt.y && b.lt.y <= a.lt.y)
        return 1;
    if(a.lt.x <= b.rb.x && b.rb.x <= a.rb.x && a.rb.y <= b.rb.y && b.rb.y <= a.lt.y)
        return 1;

    if(b.lt.x <= a.lt.x && a.lt.x <= b.rb.x && b.rb.y <= a.lt.y && a.lt.y <= b.lt.y)
        return 1;
    if(b.lt.x <= a.lt.x && a.lt.x <= b.rb.x && b.rb.y <= a.rb.y && a.rb.y <= b.lt.y)
        return 1;
    if(b.lt.x <= a.rb.x && a.rb.x <= b.rb.x && b.rb.y <= a.lt.y && a.lt.y <= b.lt.y)
        return 1;
    if(b.lt.x <= a.rb.x && a.rb.x <= b.rb.x && b.rb.y <= a.rb.y && a.rb.y <= b.lt.y)
        return 1;

    return 0;
}
