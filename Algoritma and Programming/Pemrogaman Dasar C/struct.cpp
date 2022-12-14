#include <stdio.h>

typedef struct dosen
{
    char kodeDosen[101];
    char namaDosen[101];
    char kelaminDosen[101];
    int jumlahMhs;
} dsn;

typedef struct mahasiswa
{
    char kodeMhs[101];
    char namaMhs[101];
    char kelaminMhs[101];
    char ayahMhs[101];
    char ibuMhs[101];
    int saudara;
} mhs;

    dsn infoDsn[101];
    mhs infoMhs[150][150];
int main()
{
    int jmlhDosen;
    scanf("%d", &jmlhDosen);

    int cetak;
    
    for (int i = 0; i < jmlhDosen; i++)
    {
        scanf("%s", infoDsn[i].kodeDosen);
        scanf("%s", infoDsn[i].namaDosen);
        scanf("%s", infoDsn[i].kelaminDosen);
        scanf("%d", &infoDsn[i].jumlahMhs);

        for (int j = 0; j < infoDsn[i].jumlahMhs; j++)
        {
            scanf("%s", infoMhs[i][j].kodeMhs);
            scanf("%s", infoMhs[i][j].namaMhs);
            scanf("%s", infoMhs[i][j].kelaminMhs);
            scanf("%s", infoMhs[i][j].ayahMhs);
            scanf("%s", infoMhs[i][j].ibuMhs);
            scanf("%d", &infoMhs[i][j].saudara);
        }
    }
    
    scanf("%d", &cetak);
    printf("Kode Dosen: %s\n", infoDsn[cetak-1].kodeDosen);
    printf("Nama Dosen: %s\n", infoDsn[cetak-1].namaDosen);
    printf("Gender Dosen: %s\n", infoDsn[cetak-1].kelaminDosen);
    printf("Jumlah Mahasiswa: %d\n", infoDsn[cetak-1].jumlahMhs);

    for (int i = 0; i < infoDsn[cetak-1].jumlahMhs; i++)
    {
        printf("Kode Mahasiswa: %s\n", infoMhs[cetak-1][i].kodeMhs);
        printf("Nama Mahasiswa: %s\n", infoMhs[cetak-1][i].namaMhs);
        printf("Gender Mahasiswa: %s\n", infoMhs[cetak-1][i].kelaminMhs);
        printf("Nama Ayah: %s\n", infoMhs[cetak-1][i].ayahMhs);
        printf("Nama Ibu: %s\n", infoMhs[cetak-1][i].ibuMhs);
        printf("Jumlah Saudara Kandung: %d\n", infoMhs[cetak-1][i].saudara);
    }
}