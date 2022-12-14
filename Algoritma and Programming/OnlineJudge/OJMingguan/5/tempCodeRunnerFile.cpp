#include <stdio.h>

int main()
{
    char a[100], b[100], c[100];
    for (int i = 0; i < 2; i++)
    {
        scanf("%s%s%s", a, b, c);
        printf("%sszs %sszs %sszs", a, b, c);
        printf("\n");
    }
}