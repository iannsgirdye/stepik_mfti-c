int delim_konfety(int a)
{
    static count = 0;
    count += 1;
    if(a == 1)
    {
        return count;
    }
    return delim_konfety(a / 2 + a % 2);
}
