#include <stdio.h>

int count = 0;
void SubArraySum(int array[], int size, int target)
{

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[j] + array[i] == target)
			{
				count++;
			}
		}
	}

	printf("%d", count);
}
int main()
{
	int input;
	scanf("%d", &input);
	int num[100];
	for (int i = 0; i < input; i++)
	{
		scanf("%d", &num[i]);
	}
	int target;
	scanf("%d", &target);
	SubArraySum(num, input, target);
}