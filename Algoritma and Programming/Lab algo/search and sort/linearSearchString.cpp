#include <stdio.h>
#include <string.h>

struct siswa
{
    char nama[255];
    int kelas;
} profil[255];

int siswaCount = 0;

void linearSearch(char cari[])
{
    for (int i = 0; i < siswaCount; i++)
    {
        if (strstr(profil[i].nama,cari))
        {
           printf("%s %d", profil[i].nama, profil[i].kelas);
        }
        
    }
    
}

int main()
{
    FILE *siswa;
    siswa = fopen("siswa.txt", "r");

    char nama[255];
    int kelas;

    while (!feof(siswa))
    {
        fscanf(siswa, "%[^#]#%d\n", nama, &kelas);

        strcpy(profil[siswaCount].nama, nama);
        profil[siswaCount].kelas = kelas;
        siswaCount++;
    }

    char cari[255];
    scanf("%[^\n]",cari);

    linearSearch(cari);

    // printf("%s %d", profil[2].nama, profil[2].kelas);
}