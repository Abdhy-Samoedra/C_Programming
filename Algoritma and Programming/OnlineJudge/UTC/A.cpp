#include <stdio.h>

int main()
{
    int kasus;
    int size1;
    int size2;
    
    

    scanf("%d",&kasus);

    for (int i = 0; i < kasus; i++)
    {
        scanf("%d",&size1);
        scanf("%d",&size2);

        int matrix1[size1][size1] = {};
        int matrix2[size2][size2] = {};

        for (int j = 0; j < size1; j++)
        {
            for (int k = 0; k < size1; k++)
            {
                scanf("%d",&matrix1[j][k]);
            }
            
        }

        for (int j = 0; j < size2; j++)
        {
            for (int k = 0; k < size2; k++)
            {
                scanf("%d",&matrix2[j][k]);
            }
            
        }


        int proses;

        proses = size1-size2+1;

        int hasil[proses][proses] = {};

        for (int l = 0; l < proses; l++)
        {
            for (int m = 0; m < proses; m++)
            {
                for (int n = 0; n < size2; n++)
                {
                    for (int o = 0; o < size2; o++)
                    {
                        hasil[l][m] += matrix1[n+l][o+m]*matrix2[n][o];
                    }
                    
                }
                
            }
            
        }

        for (int p = 0; p < proses; p++)
        {
            int spasi=0;
            for (int q = 0; q < proses; q++)
            {
                if (spasi==0)
                {
                    printf("");
                }else
                {
                    printf(" ");
                }
                printf("%d",hasil[p][q]);
                
				spasi++;
            }
            printf ("\n");
            
            
        }
                
    }
       
}