#include <stdio.h>
#include <math.h>

int main()
{

    // OPERATOR ARITMATIKA

    // int a, b;

    // printf("Inputkan nilai a = ");
    // scanf("%d",&a);

    // printf("inputkan nilai b = ");
    // scanf("%d",&b);


    // puts("\nARITMATIKA");

    // printf("hasil dari a + b = %d\n",a + b);
    // printf("hasil dari a - b = %d\n",a - b);
    // printf("hasil dari a / b = %d\n",a /b);
    // printf("hasil dari a * b = %d\n",a * b);
    // printf("hasil dari a sisa bagi b = %d\n",a % b);


    // OPERATOR PENUGASAN
    // operator penugasan biasanya untuk mengisi nilai
    // contoh b += a sama seperti b = b + a
    // puts("\nPENUGASAN");
    // printf("a = %d\n",a);
    // printf("b = %d\n",b);
    // printf("hasil dari a += b = %d\n",a += b); 
    // printf("hasil dari a -= b = %d\n",a -= b);
    // printf("hasil dari a /= b = %d\n",a /=b);
    // printf("hasil dari a *= b = %d\n",a *= b);
    // printf("hasil dari a sisa bagi b = %d\n",a %= b);


    // OPERATOR PEMBANDING
    // operator pembanding memiliki keluaran TRUE/FALSE 1/0
    // puts("\nPEMBANDING");
    // printf("a = %d\n",a);
    // printf("b = %d\n",b);
    // printf("a > b = %d\n", a > b);
    // printf("a < b = %d\n", a < b);
    // printf("a >= b = %d\n", a >= b);
    // printf("a <= b =  %d\n", a <= b);
    // printf("a == b = %d\n", a == b);
    // printf("a != b = %d\n", a != b);


    // OPERATOR LOGIKA
    // operator untuk membuat operasi logika seperti gerbang logika and or not
    // puts("\nLOGIKA");
    // int c = 1; //true
    // int d = 0; //false
    // printf("c = %d\n",c);
    // printf("d = %d\n",d);
    // // AND
    // printf("c && d = %d\n",c && d); 
    // // OR
    // printf("c || d = %d\n", c || d);
    // // NOT
    // printf("c !  = %d\n", !c);



    // OPERATOR BITWISE
    // operator yang berjalan berdasarkan bit atau biner
    // contoh penggunaan operator bitwise
    // 6 & 3 (and) maka sama halnya seperti:
    // langkah pertama ubah 6 kedalam bentuk biner yaitu 0110
    // langkah kedua ubah 3 kedalam bentuk biner yaitu   0011
    // maka 0110 and& 0011 adalah                        0010 = 2 (dioperatorkan berjajar kebawah)
    // puts("\nBITWISE");
    // int e = 6; 
    // int f = 3; 
    // printf("e = %d\n",e);
    // printf("f = %d\n",f);
    // // // AND
    // printf("e & f = %d\n",e & f); 
    // // // OR
    // printf("e | f = %d\n", e | f);
    // // // XOR
    // printf("e ^ f  = %d\n", e ^ f);
    // // //NOT / KOMPLEMEN DIOPERATORKAN DULU DENGAN NOT LALU HASIL OPERATOR TERSEBUT DICETAK 
    // // // DENGAN KOMPLEMEN DUA
    // printf("~e = %d\n", ~e);
    // // // LEFT SHIFT <<
    // // // jadi bitwise left shift ini adalah bilangan decimal di jadikan biner dulu lalu digeser
    // // // sesuai arah nya, disini kita left shift jadi akan digeser kekiri sesuai banyaknya angka perintah
    // // // disini kita geser 2 bit kekiri
    // printf("e << 2 = %d\n",e << 2); 
    // // // RIGHT SHIFT
    // // // sama seperti left shift hanya beda arah geser nya
    // printf("e >> 1 = %d\n", e >> 1);


   /* OPERATOR LAINNYA

   alamat memori = & = untuk mengambil alamat memori scanf
   pointer       = * = untuk membuat pointer
   ternary        = ? : = untuk membuat kondisi
   increement    = ++ = untuk menambah 1 (a++print dulu baru tambah)
   decreement    = -- = untuk mengurangi 1(--a kurang dulu baru print)

   */

  // TERNARY
  // puts("\nTERNARY");
  // int ternary = 0;

  //   printf("ternary > 1 adalah %s", ternary > 1 ? "benar": "salah");

    
    int a = 10;
    printf("komplemen dari 10 = %d",~a);


    



    return 0 ;
}