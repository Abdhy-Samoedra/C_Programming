#include <stdio.h>

int main()
{
   

    int panjang;
    // SEGITIGA PASCAL
    int coef = 1;

    printf("Masukkan panjang segitiga : ");
    scanf("%d",&panjang);


     // SEGITIGA 1

    // contoh inputan 5:
    // a. i adalah 5 , 5>0 maka lanjut kebawah
    // b. i adalah 4 , 4>0 maka lanjut kebawah
    //  BEGITU SETERUSNYA SAMPAI i=1

    for (int i = panjang; i > 0; i--)
    {
        
        // Lanjutan daei atas:
        // a. j=0, i=5 maka j<5 benar cetak *
        //    j=1, i=5 maka j<5 benar cetak **
        //    j=2, i=5 maka j<5 benar cetak ***
        //    j=3, i=5 maka j<5 benar cetak ****
        //    j=4, i=5 maka j<5 benar cetak ***** (ini akan jadi baris pertama)
        // b. j=0, i=4 maka j<4 benar cetak *
        //    j=1, i=4 maka j<4 benar cetak **
        //    j=2, i=4 maka j<4 benar cetak ***
        //    j=3, i=4 maka j<4 benar cetak **** (ini akan jadi baris kedua)
        //  BEGITU SETERUSNYA SAMPAI i=1

        for (int j = 1; j < i+1; j++)
        {
            printf("%d",j);
        }
        
        printf("\n");
    }




    printf("\n");

    
    

    // SEGITIGA 2

    // contoh inputan 5:
    // a. i=1 ; 1<=5 benar lanjut bawah ++
    // b. i=2 ; 2<=5 benar lanjut bawah ++
    // c. i=3 ; 3<=5 benar lanjut bawah ++
    // d. i=4 ; 4<=5 benar lanjut bawah ++
    // e. i=5 ; 5<=5 benar lanjut bawah ++
    // f. i=6 ; 6<=5 salah stop

    for (int i = 1; i <= panjang; i++)
    {

        // lanjutan atas:
        // a. j=1  ; 1<=1 benar ++ cetak * (baris pertama)
        //    j=2  ; 2<=1 salah stop
        // b. j=1  ; 1<=2 benar ++ cetak *
        //    j=2  ; 2<=2 benar ++ cetak ** (baris kedua)
        //    j=3  ; 3<=2 salah stop
        // c. j=1  ; 1<=3 benar ++ cetak * 
        //    j=2  ; 2<=3 benar ++ cetak **
        //    j=3  ; 3<=3 benar ++ cetak *** (baris ketiga)
        //    j=4  ; 4<=3 salah stop
        // d. j=1  ; 1<=4 benar ++ cetak *
        //    j=2  ; 2<=4 benar ++ cetak **
        //    j=3  ; 3<=4 benar ++ cetak ***
        //    j=4  ; 4<=4 benar ++ cetak **** (baris keempat)
        //    j=5  ; 3<=4 salah stop
        // e. j=1  ; 1<=5 benar ++ cetak * 
        //    j=2  ; 2<=5 benar ++ cetak **
        //    j=3  ; 1<=5 benar ++ cetak ***
        //    j=4  ; 2<=5 benar ++ cetak ****
        //    j=5  ; 2<=5 benar ++ cetak ***** (baris kelima)
        //    j=6  ; 1<=5 salah stop
        
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        
        printf("\n");
    }


    printf("\n");


    // SEGITIGA 3

    // contoh inputan 3:
    // a. i=0 ; 0<3 benar lanjut bawah ++
    // b. i=1 ; 1<3 benar lanjut bawah ++
    // b. i=2 ; 2<3 benar lanjut bawah ++
    // b. i=3 ; 3<3 salah, stop


    for (int i = 0; i < panjang; i++)
    {

        // perintah 1
        // a. j=0 ; 0<3-0 benar cetak " "
        //    j=1 ; 1<3-0 benar cetak "  "
        //    j=2 ; 2<3-0 benar cetak "    "  (baris pertama)
        //    j=3 ; 3<3-0 salah kembali keatas
        // b. j=0 ; 0<3-1 benar cetak " "
        //    j=1 ; 1<3-1 benar cetak "  "  (baris kedua)
        //    j=2 ; 2<3-1 salah kembali keatas
        // c. j=0 ; 0<3-2 benar cetak " "  (baris ketiga)
        //    j=1 ; 1<3-2 salah kembali keatas
        

        for (int j = 0; j < panjang-i; j++)
        {
            printf(" ");
        }

        //perintah 2
        // a. j=0 ; 0<0*2+1 benar cetak * (baris pertama)
        //    j=1 ; 1<0*2+1 salah kembali keatas
        // b. j=0 ; 0<1*2+1 benar cetak * 
        //    j=1 ; 1<1*2+1 benar cetak **
        //    j=2 ; 2<1*2+1 benar cetak ***  (baris kedua)
        //    j=3 ; 3<1*2+1 salah kembali keatas
        // c. j=0 ; 0<2*2+1 benar cetak * 
        //    j=1 ; 1<2*2+1 benar cetak **
        //    j=2 ; 2<2*2+1 benar cetak ***  
        //    j=3 ; 1<2*2+1 benar cetak ****
        //    j=4 ; 2<2*2+1 benar cetak *****  (baris ketiga)
        //    j=5 ; 3<2*2+1 salah kembali keatas

        for (int j = 1; j < i*2+1+1; j++)
        {
            printf("%d",j);
        }
        
        printf("\n");
    }

    printf("\n");



    // SEGITIGA 4


    for (int i = 0; i < panjang; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j < 2*(panjang-i); j++)
        {
            printf("%d",j );
        }
        
        printf("\n");
    }

    printf("\n");

    // SEGITIGA PASCAL
    


    
    for (int i = 0; i < panjang; i++) {
        for (int j = 1; j <= panjang - i; j++)
            printf("  ");
        for (int k = 0; k <= i; k++) {
            if (k == 0 || i == 0)
                coef = 1;
            else
                coef = coef * (i - k + 1) / k;
            printf("%4d", coef);
        }
        printf("\n");
    }

    printf("\n");
   

    

    



    // PERSEGI
    // contoh inputan 3:
    // a. i=0 ; 0<3 benar lanjut bawah ++
    // b. i=1 ; 1<3 benar lanjut bawah ++
    // c. i=2 ; 2<3 benar lanjut bawah ++
    // c. i=3 ; 3<3 salah stop



    for (int i = 0; i < panjang; i++)
    {
        // lanjutan atas
        // a. j=0 ; 0<3-0 benar lanjut bawah
        //    j=1 ; 1<3-0 benar lanjut bawah
        //    j=2 ; 2<3-0 benar lanjut bawah
        //    j=3 ; 3<3-0 salah balik awal cetak enter
        // b. j=0 ; 0<3-1 benar lanjut bawah
        //    j=1 ; 1<3-1 benar lanjut bawah
        //    j=2 ; 1<3-2 salah balik awal  cetak enter         
        // c. j=0 ; 0<3-2 benar lanjut bawah
        



        for (int j = 0; j < panjang-i; j++)
        {
            // lanjutan atas
            // a.1 k=0 ; k<3-0 benar cetak #
            //     k=1 ; k<3-0 benar cetak ##
            //     k=2 ; k<3-0 benar cetak ### (baris 1 kotak 1)
            //     k=3 ; k<3-0 salah balik atasnya
            // a.2 k=0 ; k<3-0 benar cetak #
            //     k=1 ; k<3-0 benar cetak ##
            //     k=2 ; k<3-0 benar cetak ### (baris 2 kotak 1)
            //     k=3 ; k<3-0 salah balik atasnya
            // a.3 k=0 ; k<3-0 benar cetak #
            //     k=1 ; k<3-0 benar cetak ##
            //     k=2 ; k<3-0 benar cetak ### (baris 3 kotak 1)
            //     k=3 ; k<3-0 salah balik atasnya
            // b.1 k=0 ; k<3-1 benar cetak #
            //     k=1 ; k<3-1 benar cetak ##  (baris 1 kotak 2)
            //     k=2 ; k<3-1 salah balik atasnya
            // b.2 k=0 ; k<3-1 benar cetak #
            //     k=1 ; k<3-1 benar cetak ##  (baris 2 kotak 2)
            //     k=2 ; k<3-1 salah balik atasnya
            // c.1 k=0 ; k<3-2 benar cetak #
            //     k=1 ; k<3-2 salah balik atas


            for (int k = 0; k < panjang - i ; k++)
            {
                printf("#");
            }
            
            printf("\n");
        }

        printf("\n");
        
    }

    return 0;
    


    
}
