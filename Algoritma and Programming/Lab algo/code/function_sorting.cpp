#include <stdio.h>


void menu()
{
    printf("menu\n");
    printf("1.insert\n");
    printf("2. View\n");
}

int printnumber()
{
    return 10;
}

int penjumlahan(int angka1, int angka2)
{
    int hasil;
    hasil = angka1 + angka2;
    return hasil;
}

int pow(int angka, int pangkat)
{
    int hasil=1;
    for (int i = 0; i < pangkat; i++)
    {
        hasil *=angka;
    }
    return hasil;
}

void inputNumber(int *angka1, int *angka2)
{
    scanf("%d %d",angka1,angka2);
}

int factorial(int value)
{
    //base case (sesuatu yang sudah kita ketahui 0! = 1)
    if (value == 0) return 1;
    


    //pemanggilan fungsi itu sendiri
    return value*factorial(value-1);
}


//SORTING
// 1 buble sort = akan melakukan penukaran setiap kali bertremu dengan nilai/angka yang lebih kecil/besar yang berada kanannya

void bublesort1()
{
    // value yang akan diurutkan
    int arr[5] = {5,2,1,4,3};
    int length = 5;

    //lakukan looping sampai undex terkahir - 1

    for (int i = 0; i <length-1; i++)
    {
        //looping sampai index terakhir -1 -1
        for (int j = 0; j<length-1-i; j++)
        {
            //menjalankan cheking dengan angka sampingnya apakah lebih besar atau kecil
            // kiri = j
            // kanan - j + 1
            if (arr[j]<arr[j+1])
            {
                //karena sudah lebih kecil maka tidak perlu dipindahkan
            }else
            {
                //lebih besar maka ditukar
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d",arr[i]);
    }
    
}

void bublesort2()
{
    // value yang akan diurutkan
    int arr[5] = {5,2,1,4,3};
    int length = 5;

    //lakukan looping sampai undex terkahir - 1

    for (int i = 0; i <length-1; i++)
    {
        //looping sampai index terakhir -1 -1
        for (int j = 0; j<length-1-i; j++)
        {
            //menjalankan cheking dengan angka sampingnya apakah lebih besar atau kecil
            // kiri = j
            // kanan - j + 1
            if (arr[j]>arr[j+1])
            {
                //karena sudah lebih kecil maka tidak perlu dipindahkan
            }else
            {
                //lebih besar maka ditukar
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d",arr[i]);
    }
    
}



// 2. insertion sorting dari kirinya dulu, bisa juga ketika kita ingin sorting nilai langsung saat di input

//pendukung insertion sort pada kasus ini, karena hasrusnya insertion sort value nya berasal dari inputan, dan akan langsung diurutkan

int sortedArrayResult[5] = {};

void sort(int limit)
{
    //logic sortnya
    for (int i = 0; i < limit-1; i++)
    {
        if (sortedArrayResult[i] <= sortedArrayResult[limit])
        {

        }else
        {
            int temp = sortedArrayResult[i];
            sortedArrayResult[i] = sortedArrayResult[limit];
            sortedArrayResult[limit]=temp;
        }
        
        
    }
    

}

void insertionsort()
{
    //function ini dimisalkan sebagai inputan
    int arr[5] = {5,2,1,4,3};

    for (int i = 0; i < 5; i++)
    {
        //memasukkan satu data
        sortedArrayResult[i] = arr[i];
        //setiap satu data dicek dan di sorting
        sort(i);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d",sortedArrayResult[i]);
    }
    puts("");
}


//3 selection sort

void selectionsort()
{
    int arr[5] = {5,2,1,4,3};

    for (int i = 0; i < 5; i++)
    {
        int minIdx = 0;
        for (int j = i; j < 5; j++)
        {
            //logic untuk tandain angka terkecil
            if (j==i)
            {
                minIdx = j;
            }else if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }

            if (minIdx == i)
            {
                
            }else
            {
                int temp = arr[i];
                arr[i] = arr[minIdx];
                arr[minIdx] = temp;
            }
            
            
            
        }
        
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d",arr[i]);
    }
    puts("");
    
}



 

int main()
{
    // menu();

    // int number = printnumber();
    // printf("%d\n",number);

    // int angka1 = 10;
    // int angka2 = 12;
    // int hasil = penjumlahan(angka1,angka2);
    // printf("%d\n",hasil);

    // int angka = 5;
    // int pangkat = 4;
    // int hasilpangkat;
    // hasilpangkat = pow(angka,pangkat);
    // printf("%d\n",hasilpangkat);


    // int num1,num2;
    // inputNumber(&num1,&num2);
    // printf("%d %d\n",num1,num2);

    // int satu,dua;
    // inputNumber(&satu,&dua);
    // printf("%d %d\n",satu,dua);


    // // factorial rekursif
    // int hasilfaktorial = factorial(0);
    // printf("%d\n",hasilfaktorial);

    printf("buble up sorting: ");
    bublesort1();
    printf("\n");
    printf("buble down sorting: ");
    bublesort2();
    printf("\n");
    printf("insertion sorting: ");
    insertionsort();
    printf("selection sorting: ");
    selectionsort();
    printf("\n");







    return 0;
}