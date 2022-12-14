#include <stdio.h>
int hitung(int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 1;
    }
    else
    {
        return hitung(m - 1, n - 1) + hitung(m - 1, n) + hitung(m, n - 1);
    }
}
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d\n", hitung(m, n));
}