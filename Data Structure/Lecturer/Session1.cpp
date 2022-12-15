#include <stdio.h>

int main()
{
    // int x = 10;
    // int *px = &x;
    // printf("value of x = %d\n",x);
    // printf("value of px = %d\n",px);
    // printf("addres of x = %d\n",&x);

    // *px = 100;

    // printf("new value of x = %d\n",x);
    // printf("value of px = %d\n",*px);

    int a = 10;
    int *p = &a;

    printf("%d ",a);
    printf("%d ",&a);
    printf("%d ",p);
    printf("%d ",*p);
    printf("%d \n",&p);

    a = 17;
    *p = 20;
    *p = 100;
    a= 29;
    printf("%d ",a);
    printf("%d \n",*(&a));

    int num[5];
    for (int i = 0; i < 5; i++)
    {
        printf("alamat array %d = %d\n",i,&num[i]);
    }
    





}