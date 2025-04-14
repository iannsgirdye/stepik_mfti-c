// struct Point
// {
//     int x;
//     int y;
// };

struct Rect1
{
    struct Point lt;
    struct Point rb;
};

struct Rect1 b;
b.lt.x = -7;
b.lt.y = 5;
b.rb.x = 5;
b.rb.y = -3;
