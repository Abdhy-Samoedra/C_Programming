#include <stdio.h>

int main()
{
	int size;
	int matrix[100][100];
	int matrix2[100][100];
	int matrixhasil[100][100];
	
	scanf("%d",&size);
	for(int i = 0; i<size;i++)
	{
		for(int j =0;j<size;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
	for(int i = 0; i<size;i++)
	{
		for(int j = 0;j<size;j++)
		{
			scanf("%d",&matrix2[i][j]);
		}
	}
	
	for(int i = 0; i<size;i++)
	{
		for(int j = 0; j<size;j++)
		{
			matrixhasil[i][j] = 0;
			for (int k = 0;k<size;k++)
			{
				matrixhasil[i][j]= matrixhasil[i][j] + matrix[i][k] * matrix2[k][j];
			}
		}
	}
	
	for(int i =0;i<size;i++)
	{
		for(int j = 0; j<size;j++)
		{
			printf("%d ",matrixhasil[i][j]);
		}
		printf("\n");
	}
	
}
