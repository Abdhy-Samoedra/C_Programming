#include <stdio.h>

int main()
{
	int kasus;
	int rate;
	int time;
	long long int amount;
	scanf("%d %lld", &kasus, &amount);
	for (int i = 0; i < kasus; i++)
	{
		scanf("%d %d", &rate, &time);
		amount += ((amount * rate / 100) * time / 12);
	}
	printf("IDR %d", amount);
}
