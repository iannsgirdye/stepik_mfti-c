void sort2(int * a, int * b)
{   
    if(*a > *b)
    {
        int x = *a;
        *a = *b;
        *b = x;
    }
}

void sort3(int * x, int * y, int * z)
{
    if(*y <= *z && *y <= *x)
        sort2(x, y);
    else if(*z <= *x && *z <= *y)
        sort2(x, z);
    sort2(y, z);
}
