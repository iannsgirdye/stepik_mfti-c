void sort2(int * a, int * b)
{
    int local_a = *a, 
        local_b = *b;
    
    if(local_a > local_b)
    {
        *a = local_b;
        *b = local_a;
    }
}
