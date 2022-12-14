#include <stdio.h>

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	int j = low;

	while (j < high)
	{
		if (arr[j] <= pivot)
		{
			i++;
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
		j++;
	}
	arr[high] = arr[i + 1];
	arr[i + 1] = pivot;
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pos = partition(arr, low, high);
		quickSort(arr, low, pos - 1);
		quickSort(arr, pos, high);
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

	quickSort(arr, 0, size - 1);

	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}
