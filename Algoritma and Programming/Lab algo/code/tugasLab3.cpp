#include <stdio.h>

int main()
{

    while (1)
    {
    puts("Shape Printer");
    puts("=============");
    puts("1.Rectangle");
    puts("2.Rigth Triangle (90 degree triangle)");
    puts("3.Equiateral Triangle");
    puts("4.Exit");
    printf(">> ");
    

    int menu;

    scanf("%d",&menu);
    

    switch (menu)
    {
    case 1:
        int width,heigth;

        width = -1;
        heigth = -1;

        while (width <= 0)
        {
            printf("width must be more than 0: ");
            scanf("%d",&width);
        }

        while (heigth <= 0)
        {
            printf("heigth must be more than 0: ");
            scanf("%d",&heigth);
        }

        for (int i = 0; i < heigth; i++)
        {
            for (int j = 0; j < width; j++)
            {
                printf("*");
            }
            
            printf("\n");
        }
        
        
        break;
    case 2:
        int size;

        size = -1;

        while (size <= 0)
        {
            printf("size must be more than 0: ");
            scanf("%d",&size);
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 1; j < size-i; j++)
            {
                printf(" ");
            }
            for (int k = 0; k <= i; k++)
            {
                printf("*");
            }
            
            printf("\n");
            
        }
        break;
    case 3:
        int size2;

        size2 = -1;

        while (size2 <= 0)
        {
            printf("size must be more than 0: ");
            scanf("%d",&size2);

        }
        for (int i = 0; i < size2; i++)
        {

            for (int j = 1; j < size2-i; j++)
            {
                printf(" ");
            }
            for (int j = 1; j < i*2+1+1; j++)
            {
                printf("*");
            }

            printf("\n");
        }
        
        break;
    
    case 4:
        printf("Thank you");
        return 0;
        break;
    
    default:
        printf("angka salah");
        break;
    }
    }
    
    

}