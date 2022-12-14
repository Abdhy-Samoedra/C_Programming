#include <stdio.h>

int main()
{
    int n;
    for (; ;)
    {
         printf("\n Enter integer : ");  scanf("%d ", &n);
             if((n%2) == 0) break;
             else if((n%3) == 0) break;
             printf("\n\t Bottom of loop.");

    }
    printf("\n\t Outside of loop.");

}