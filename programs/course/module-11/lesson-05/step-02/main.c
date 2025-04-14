char * my_strcat(char *dest, const char *src)
{
    int i;
    int dest_len = strlen(dest);
    int src_len = strlen(src);
    for(i = 0; i < src_len; i++)
        dest[dest_len + i] = src[i];

    dest[dest_len + i] = src[i];
    return dest;
}
