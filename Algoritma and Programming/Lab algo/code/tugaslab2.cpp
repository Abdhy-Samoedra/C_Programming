#include <stdio.h>
#include <math.h>

int main()
{

    //deklarasi variabel
    int x;
    int result1;
    int result2;
    int result3;

    puts("Operators");
    puts("=============");
    printf("Input your Favorite Number: ");

    scanf("%d",&x);

    //iniisialisasi operasi aritmatika
    result1 = 2*x + 3;
    result2 = (result1/3)-4;
    result3 = result2;
    result3 *= result2; // shorthand operator

    //hasil result
    printf("Result 1 = %d\n",result1);
    printf("Result 2 = %d\n",result2);
    printf("Result 3 = %d\n",result3);


    // memasukkan pointer y kedalam x 

    int* y; //deklarasi/cara membuat POINTER

    y = &x; //memanggil alamat x dengan simbol &

    printf("%d\n",*y); // print pointer *y

    // int y;
    // y=x;
    // printf("%d",y);
    
    if (*y >= 10)
    {
        printf("Y is bigger or equals 10\n");
    }else 
    {
        printf("Y is smaller than 10\n");
    }

    // dengan operator TERNARY    
    printf("y is = %s\n", (*y % 2 == 0) ? "genap" : "ganjil");

    // switch case

    switch (*y)
    {
    case 10:
        printf("Y adalah 10");
        break;
    case 9:
        printf("Y adalah 9");
        break;
    case 8:
        printf("Y adalah 8");
        break;
    case 7:
        printf("Y adalah 7");
        break;
    case 6:
        printf("Y adalah 6");
        break;
    
    default:
        break;
    }
    
    

    



    return 0;
}