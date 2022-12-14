#include <stdio.h>

int main()
{
    int a = 5;
    int *ptr;
    ptr=&a;
    printf("%d %d %d %d\n",ptr,*ptr,&a,a);

    *ptr=6;
    printf("%d %d %d %d\n",ptr,*ptr,&a,a);

    int **ptr_ptr;
    ptr_ptr=&ptr;
    printf("%d %d %d %d %d %d\n",ptr_ptr,**ptr_ptr,ptr,*ptr,&a,a);

    **ptr_ptr=10;
    printf("%d %d %d %d %d %d\n",ptr_ptr,**ptr_ptr,ptr,*ptr,&a,a);
    

    
}