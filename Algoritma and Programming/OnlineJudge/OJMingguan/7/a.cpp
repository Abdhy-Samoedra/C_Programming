#include <stdio.h>

int main()
{
    FILE*coba;
    int a,b;
    coba = fopen("testdata.in","r");

    fscanf(coba,"%d %d",&a,&b);
    printf("%d\n",a+b);
    fclose(coba);
}