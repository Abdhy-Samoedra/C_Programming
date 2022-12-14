#include <stdio.h>
void bublesort1()
{
    // value yang akan diurutkan
    int arr[5] = {5, 2, 1, 4, 3};
    int length = 5;

    // lakukan looping sampai undex terkahir - 1

    for (int i = 0; i < length - 1; i++)
    {
        // looping sampai index terakhir -1 -1
        for (int j = 0; j < length - 1 - i; j++)
        {
            // menjalankan cheking dengan angka sampingnya apakah lebih besar atau kecil
            //  kiri = j
            //  kanan - j + 1
            if (arr[j] < arr[j + 1])
            {
                // karena sudah lebih kecil maka tidak perlu dipindahkan
            }
            else
            {
                // lebih besar maka ditukar
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d", arr[i]);
    }
}
int main()
{
    printf("buble up sorting: ");
    bublesort1();
}