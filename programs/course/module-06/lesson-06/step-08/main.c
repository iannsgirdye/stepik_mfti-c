// struct Point {
//     int x;
//     int y;
// };
// struct Rect {
//     struct Point lt; // левая верхняя вершина
//     struct Point rb; // правая нижняя вершина
// };


struct Rect * max(struct Rect * pa, struct Rect * pb)
{
    int first_a = pa->rb.x - pa->lt.x;   // разница абсцисс первого прямоугольника --- сторона, параллельная оси абсцисс
    int first_b = pa->lt.y - pa->rb.y;   // разница ординат первого прямоугольника --- сторона, параллельная оси ординат
    int second_a = pb->rb.x - pb->lt.x;  // разница абсцисс второго прямоугольника --- сторона, параллельная оси абсцисс
    int second_b = pb->lt.y - pb->rb.y;  // разница ординат второго прямоугольника --- сторона, параллельная оси ординат

    int first_S = first_a * first_b;     // площадь первого прямоугольника
    int second_S = second_a * second_b;  // площадь второго прямоугольника

    if(first_S > second_S)
        return pa;
    return pb;
}
