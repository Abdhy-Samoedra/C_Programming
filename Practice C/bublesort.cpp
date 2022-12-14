#include <stdio.h>

void bubleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
			}
			else
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int size;
	scanf("%d", &size);

	int arr[100];

	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	bubleSort(arr, size);

	for (int j = 0; j < size; j++)
	{
		printf("%d ", arr[j]);
	}
}
