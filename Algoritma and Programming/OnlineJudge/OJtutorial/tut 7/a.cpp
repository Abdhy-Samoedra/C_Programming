#include <stdio.h>

int main()
{
    int size;

    scanf("%d",&size);

    int matrix[101][101];
    int transpose[101][101];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
        
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            transpose[i][j] = matrix[j][i];
        }
        
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d",transpose[i][j]);
            if (j<size-1)
            {
                printf(" ");
            }
            
        }
        printf("\n");
        
    }
    
    
    
       
}