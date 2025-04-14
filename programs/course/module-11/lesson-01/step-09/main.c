void elong_set(Decimal * res, const char str[])
{
    res->n = -1;                            // счётчик степеней 10
    for(int i = 0; str[i] != '\0'; i++)     // вычисление наибольшей степени 10
        (res->n)++;

    for(int i = 0; i <= res->n; i++)        // преобразование числа
        res->a[i] = str[res->n - i] - '0';
}

