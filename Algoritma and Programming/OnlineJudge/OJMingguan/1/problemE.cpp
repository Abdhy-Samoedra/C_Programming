#include <stdio.h>

int main()
{
    int x,a1,b1,a2,b2,a3,b3;

    scanf("%d",&x);
    scanf("%d %d",&a1,&b1);
    scanf("%d %d",&a2,&b2);
    scanf("%d %d",&a3,&b3);

    printf("%d\n",((a1/b1)<<b1));
    printf("%d\n",((a2/b2)<<b2));
    printf("%d\n",((a3/b3)<<b3));
}