#include <stdio.h>

int main()
{
	int baris1, kolom1, baris2, kolom2;

	scanf("%d %d", &baris1, &kolom1);
	scanf("%d %d", &baris2, &kolom2);

	if (kolom1 != baris2)
	{
		printf("perkalian matrix tidak bisa diproses\n");
		return 0;
	}

	int matrix1[100][100];
	int matrix2[100][100];
	int matrixhasil[100][100];

	for (int i = 0; i < baris1; i++)
	{
		for (int j = 0; j < kolom1; j++)
		{
			scanf("%d", &matrix1[i][j]);
		}
	}
	for (int i = 0; i < baris2; i++)
	{
		for (int j = 0; j < kolom2; j++)
		{
			scanf("%d", &matrix2[i][j]);
		}
	}

	for (int i = 0; i < baris1; i++)
	{
		for (int j = 0; j < kolom2; j++)
		{
			matrixhasil[i][j] = 0;
			for (int k = 0; k < baris2; k++)
			{
				matrixhasil[i][j] = matrixhasil[i][j] + matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	for (int i = 0; i < baris1; i++)
	{
		for (int j = 0; j < kolom2; j++)
		{
			printf("%d ", matrixhasil[i][j]);
		}
		printf("\n");
	}
}
