#ifndef GEOMETRY_H
#define GEOMETRY_H


struct Point {
    int x;
    int y;
};


struct Rect {
    struct Point lt;  // левая верхняя вершина
    struct Point rb;  // правая нижняя вершина
};


#endif  // GEOMETRY_H
