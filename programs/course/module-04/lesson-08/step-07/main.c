void min2time(int mm, int * ph, int * pm)
{
    *ph = (mm / 60) % 24;
    *pm = mm % 60;
}
