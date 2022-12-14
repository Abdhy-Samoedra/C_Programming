#include <stdio.h>
#include <math.h>

int studentCount = 0;

int partition(int data[], int low, int high)
{
    int j = low, i = low - 1, pivot = data[high];
    while (j < high)
    {
        if (data[j] < pivot)
        {
            i++;
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
        j++;
    }
    data[high] = data[i + 1];
    data[i + 1] = pivot;
    return i + 1;
}

void quickSort(int data[], int low, int high)
{
    if (low >= high)
        return;
    int pos = partition(data, low, high);
    quickSort(data, low, pos - 1);
    quickSort(data, pos + 1, high);
}

int selisih(int data[])
{
    quickSort(data, 0, studentCount - 1);
    long long int sum1 = 0, sum2 = 0;
    sum1 = data[studentCount - 1], sum2 = data[studentCount - 2];
    for (int i = studentCount - 3; i >= 0; i--)
    {
        if (abs(sum1 + data[i] - sum2) > abs(sum2 + data[i] - sum1))
            sum2 += data[i];
        else
            sum1 += data[i];
    }
    return abs(sum1 - sum2);
}

int main()
{
    FILE *student;
    student = fopen("testdata.txt", "r");
    int cases;
    fscanf(student, "%d\n", &cases);
    for (int i = 1; i <= cases; i++)
    {
        fscanf(student, "%d\n", &studentCount);
        int data[studentCount + 10] = {};
        for (int j = 0; j < studentCount; j++)
        {
            if (j != studentCount - 1)
                fscanf(student, "%d ", &data[j]);
            else
                fscanf(student, "%d\n", &data[j]);
        }
        printf("Case #%d: %d\n", i, selisih(data));
    }
    fclose(student);
    return 0;
}