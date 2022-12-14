#include <stdio.h>
#include <math.h>

//array harus ditentukan panjangnnya
// contoh int nama_array [4] = {0,1,2,3}

int main(){
    // //cara pengambilan array

    // char huruf [5] = {'a', 'b', 'c', 'd', 'e'};

    // // mengubah isi array

    // huruf[2] = 'x';

    // printf("hurufnya adalah : %c", huruf[2]);

    //menigisi array kosong

    // int array_kosong [4];

    //mengisi array
    // array_kosong [0] = 4;
    // array_kosong [1] = 5;
    // array_kosong [2] = 8;
    // array_kosong [3] = 9;

    // printf("angkanya adalah : %d", array_kosong[2]);

    //Perulangan array

    // int array_kosong [4];

    // array_kosong [0] = 4;
    // array_kosong [1] = 5;
    // array_kosong [2] = 8;
    // array_kosong [3] = 9;

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("angkanya adalah : %d  \n",array_kosong[i]);
    // }


    //mengambil panjang array

    int array [4] = {1, 2, 3, 4};
    
    int length = sizeof(array) / sizeof(array[0]); // sizeof(array[0]) atau  sizeof(*array)

    // for (int i = 0; i < length; i++)
    // {
    //     printf("angkanya adalah : %d\n",array[i]);
    // }
    
    

    // Menghitung tinggi rata rata

    //  int tinggi [5] = {176, 168, 180, 190, 173};

    //  int length = sizeof(tinggi) / sizeof(*tinggi);
    //  int sum = 0;

    //  for (int i = 0; i < length; i++)
    //  {
    //     sum += tinggi[i]; // operator penugasan. sama seperti sum = sum + tinggi
    //  }

    //  float rata_rata = (float)sum / (float)length;

    //  printf("Rata rata tinggi adalah : %.2f", rata_rata)



    // Array 2 dimensi


    //  int array_multi [4][3] = {{1, 2, 3},{3, 4, 5},{6, 7, 8},{6, 7, 8}};

    //  printf("Isi array pada indeks ke (2,2) %d\n", array_multi[2][2]);
    //  printf("Isi array pada indeks ke  %d", *(array_multi+1),*(array_multi+2));

    //   return 0;
    

    // int i;
    // int list int [10];
    // for (int i = 0; i < 10; i++)
    // {
    //     list int [i] = i +1;
    //     printf("list int [%d] init with %d.\n")
    // }
    

    // Array 3 dimensi


    //  int array_multi [3][2][4] = {  { {1,2,3,4} , {5,6,7,8} }  ,{ {11,12,13,14} , {15,16,17,18} },  { {21,22,23,24} , {25,26,27,28} }   };





    // int a[5] = {1,3,5,7,9};
    // a[3]=25;
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("index %d = %d\n",i,a[i]);
    // }
    
    // for (int i = 0; i < 5; i++)
    // {
    //     a[i]=i+1;
    //     printf("index %d = %d\n",i,a[i]);
    // }
    
    // int array[3]={0,9,5};
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("index %d: %d\n",i,array[i]);
    // }

   

    
    return 0;
    
   
    

}