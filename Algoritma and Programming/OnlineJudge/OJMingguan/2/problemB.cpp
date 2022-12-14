#include <stdio.h>

int main()
{
    long int d,s,t;
    scanf("%ld %ld %ld",&d,&s,&t);

    if (d > s && d >t)
    {
        if (s > t)
        {
            printf("Daging\n");
            printf("Sayur\n");
            printf("Telur\n");
        }else if (t > s)
        {
            printf("Daging\n");
            printf("Telur\n");
            printf("Sayur\n");
        }
        
        
    }else if (s > d && s >t)
    {
        if (d > t)
        {
            printf("Sayur\n");
            printf("Daging\n");
            printf("Telur\n");
        }else if (t > d)
        {
            printf("Sayur\n");
            printf("Telur\n");
            printf("Daging\n");
        }
        
        
    }else if (t > s && t >s)
    {
        if (s > d)
        {
            printf("Telur\n");
            printf("Sayur\n");
            printf("Daging\n");
        }else if (d > s)
        {
            printf("Telur\n");
            printf("Daging\n");
            printf("Sayur\n");
        }
        
        
    }
    



}