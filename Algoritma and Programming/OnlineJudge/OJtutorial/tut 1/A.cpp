#include <stdio.h>

int main()
{
    long a;
    scanf("%d",&a);
    long sum = a+a;

    printf("%d plus %d is %d\n",a,a,sum);
    printf("minus one is %d\n",sum-1);

    return 0;

}