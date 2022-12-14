#include <stdio.h>

int main()
{
    int value = 10;
    int* ptr = &value;
    int** ptrr = &ptr;
    printf("%d %d %d %d",value,&value,**ptrr,&ptrr);
}