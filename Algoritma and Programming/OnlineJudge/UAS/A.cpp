#include <stdio.h>
#include <string.h>

struct data
{
    char id[255];
    char nama[255];
    char major[255];
    double gpa;
    char posisi[255];
} people[255];

int cek(char job[], char faculty[], double gpa, int applicant)
{

    int count = 0;
    for (int j = 0; j < applicant; j++)
    {
        if (strcmpi(job, people[j].posisi) == 0 && strcmpi(faculty, people[j].major) == 0 && people[j].gpa >= gpa)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int applicant;
    scanf("%d", &applicant);
    getchar();

    for (int i = 0; i < applicant; i++)
    {
        scanf("%s", people[i].id);
        getchar();
        scanf("%[^\n]", people[i].nama);
        getchar();
        scanf("%s", people[i].major);
        getchar();
        scanf("%lf", &people[i].gpa);
        getchar();
        scanf("%s", people[i].posisi);
        getchar();
    }

    int cases;
    scanf("%d", &cases);
    getchar();

    char job[255];
    char faculty[255];
    double gpa;
    int hasil;

    for (int i = 0; i < cases; i++)
    {
        scanf("%s %s %lf", job, faculty, &gpa);
        getchar();

        hasil = cek(job, faculty, gpa, applicant);
        printf("CASE #%d: %d\n", i + 1, hasil);
    }
}