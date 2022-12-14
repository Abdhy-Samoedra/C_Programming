#include <stdio.h>
#include <string.h>

struct data
{
	char id[255];
	char nama[255];
	char jurusan[255];
	double ipk;
	char posisi[255];
} pelamar[255];

int pelamarCount = 0;

struct data2
{
	char jurusan[255];
	double ipk;
} posisi[255];
int posisiCount = 0;

struct data3
{
	double ipk;
} ipk[255];
int ipkCount = 0;

int partition(data pelamar[], int low, int high)
{
	data pivot = pelamar[high];
	int i = low - 1;
	int j = low;

	while (j < high)
	{
		if (strcmpi(pelamar[j].posisi, pivot.posisi) < 0)
		{
			i++;
			data temp;
			temp = pelamar[j];
			pelamar[j] = pelamar[i];
			pelamar[i] = temp;
		}
		j++;
	}
	pelamar[high] = pelamar[i + 1];
	pelamar[i + 1] = pivot;
	return (i + 1);
}

void quickSort(data pelamar[], int low, int high)
{
	if (low < high)
	{
		int pos = partition(pelamar, low, high);
		quickSort(pelamar, low, pos - 1);
		quickSort(pelamar, pos + 1, high);
	}
}

int linearSearch(char cari[])
{
	for (int i = 0; i < pelamarCount; i++)
	{
		if (strcmp(pelamar[i].posisi, cari) == 0)
		{
			strcpy(posisi[posisiCount].jurusan, pelamar[i].jurusan);
			posisi[posisiCount].ipk = pelamar[i].ipk;
			posisiCount++;
		}
	}
}

int linearSearch2(char cari[])
{
	for (int i = 0; i < posisiCount; i++)
	{
		if (strcmp(posisi[i].jurusan, cari) == 0)
		{
			ipk[i].ipk = posisi[posisiCount].ipk;
			ipkCount++;
		}
	}
}

int main()
{
	FILE *lamar;
	lamar = fopen("pelamar.txt", "r");

	while (!feof(lamar))
	{
		fscanf(lamar, "%[^#]#%[^#]#%[^#]#%lf#%[^\n]\n", pelamar[pelamarCount].id, pelamar[pelamarCount].nama, pelamar[pelamarCount].jurusan, &pelamar[pelamarCount].ipk, pelamar[pelamarCount].posisi);
		pelamarCount++;
	}
	quickSort(pelamar, 0, pelamarCount - 1);
	for (int i = 0; i < pelamarCount; i++)
	{
		printf("%s %s %s %.2lf %s\n", pelamar[i].id, pelamar[i].nama, pelamar[i].jurusan, pelamar[i].ipk, pelamar[i].posisi);
	}
	char cari[255];
	scanf("%[^\n]", cari);
	getchar();
	linearSearch(cari);
	printf("%d\n", posisiCount);
	for (int i = 0; i < posisiCount; i++)
	{
		printf("%.2lf %s\n", posisi[i].ipk, posisi[i].jurusan);
	}
	int count = 0;
	if (strcmp(cari, "sales") == 0)
	{

		char cari2[255] = "marketing";
		linearSearch2(cari2);
		printf("%d\n", ipkCount);
		for (int i = 0; i < ipkCount; i++)
		{
			printf("%.2lf \n", posisi[i].ipk);
		}

		for (int i = 0; i < ipkCount; i++)
		{
			//			double batas = 3.2;
			if (posisi[i].ipk > 2.8)
			{
				count++;
			}
		}
		printf("%d", count);
	}
	else if (strcmp(cari, "Ui designer") == 0)
	{
		char cari2[255] = "Fashion";
		linearSearch2(cari2);
	}
	else if (strcmp(cari, "Accountant") == 0)
	{
		char cari2[255] = "Perbankan";
		linearSearch2(cari2);
	}

	//	printf("%.0lf",count);
}