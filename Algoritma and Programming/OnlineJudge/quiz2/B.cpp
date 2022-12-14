#include <stdio.h>

struct data
{
	char id[100];
	char name[1000];
	int age;
}data[1000];

int main()
{
	int jumlah;
	scanf("%d", &jumlah);
	getchar();

	for (int i = 0; i < jumlah; i++)
	{
		scanf("%s", data[i].id);
		getchar();
		scanf("%[^\n]", data[i].name);
		getchar();
		scanf("%d", &data[i].age);
		getchar();
	}

	int query;
	scanf("%d", &query);
	getchar();
	int hasil;
	for (int i = 0; i < query; i++)
	{
		scanf("%d", &hasil);
		getchar();
		printf("Query #%d:\n", i + 1);
		printf("ID: %s\n", data[hasil - 1].id);
		printf("Name: %s\n", data[hasil - 1].name);
		printf("Age: %d\n", data[hasil - 1].age);
	}
}
