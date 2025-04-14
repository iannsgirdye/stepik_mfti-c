#include <stdio.h>

int main()
{
    int h_in, m_in;
    scanf("%d%d", &h_in, &m_in);

    int m_out, s_out;
    m_out = h_in * 60 + m_in;
    s_out = m_out * 60;
    printf("%d\n%d\n", m_out, s_out);

    return 0;
}
