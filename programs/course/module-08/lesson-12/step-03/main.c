void elong_print(Decimal x) 
{
    for(int i = x.n; i >= 0; i--)
    {
        printf("%d", x.a[i]);
    }
    printf("\n");
}
