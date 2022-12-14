#include <stdio.h>
#include <string.h>

void linearSearch()
{
    // sediakan array  yang akan digunakan untuk mencari angka
    int arr[] = {10, 20, 30, 40, 40, 50};

    int length = sizeof(arr) / sizeof(arr[0]);

    // angka yang akan dicari
    int find = 20;

    int counter = 0;

    for (int i = 0; i < length; i++)
    {
        if (find == arr[i])
        {
            printf("%d ketemu nih di index %d\n", arr[i], i);
            counter++;
            break;
        }
    }
    if (counter == 0)
    {
        printf("tidak ada nih anying\n");
    }
}

int main()
{
    linearSearch();
    return 0;
}