#include <stdio.h>


// -----------fungsi biasanya mengembalikan nilai / memiiki return
// -----------fungsi yang tidak mengembalikan nilai adalah fungsi void()/procedure (tidak memiiki return)
// -----------Pada c++ fungsi main harus integer, jika bukan integer akan error
//------------Tetapi pada C hal tersebut tidak berlaku, fungsi main bisa berupa void atau lainnya

// void coba_fungsi()   // membuat fungsi
// {
//     printf("Ini coba fungsi\n");
// }

// int main()        // MAIN HARUS BERUPA INTEGER DAN MENGEMBALIKAN NILAI WALAUPUN 0, tadi saya coba pakai void main error karena tidak int
// {
//     coba_fungsi();
//     coba_fungsi();
//     coba_fungsi();
//     coba_fungsi();
//     coba_fungsi();
// }

// ---------------Fungsi dengan parameter
// Parameter menyimpan nilai yang akan diinputkan dan diproses dalam fungsi

//----------------fungsi dengan 1 parameter

// void hello (char nama[10])
// {
//     printf("Hello %s\n", nama);
// }

// int main()
// {
//     hello("abdhy");
//     hello("mika");
//     hello("aryo");
// }
// kode program diatas jika disimpan dengan extensi.c akan berjalan lancar
// namun jika disimpan dengan ektensi .cpp` akan tetap berjalan namun kelur warning error

//---------------fungsi dengan 2 parameter

// void penjumlahan (int a, int b)
// {
//     printf("%d + %d = %d", a, b, a+b);
// }

// int main()
// {
//     penjumlahan(2,4);
// }

// --------------Fungsi yang mengembalikan nilai
// mengembalikan nilai menggunakan return;

// float kali (int a, int b)
// {
//     float hasil = (float)a * (float)b;
//     return hasil;
// }

// int main()
// {
//     printf("Hasil perkalian 2 * 5 =  %.2f",kali(2,5));
// }

// ---------------Fungsi rekursif pada C
// Rekursif adalah fungsi yang memanggil dirinya sendiri di dalam tubuhnya,
// kan kita biasanya memanggil fungsi di main.

// int sum (int num)
// {
//     if (num != 0)
//     {
//         return num + sum(num-1);   // disini tertulis sum, menandakan memanggil dirinya sendiri dengan parameter berbeda
//     }else
//     {
//         return num;
//     }
    
    
// }

// int main()
// {
//     int number, result;

//     printf("Masukkan sebuah bilangan bulat = ");
//     scanf("%d", &number);

//     result = sum(number);

//     printf("sum = %d", result);
// }


// ----------------Variabel lokal dan variabel global
// Variabel lokal : variabel yang hanya bisa diakses difungsi itu sendiri, terdapat dalam blok fungsi itu sendiri
// Variabel Global : variabel yang bisa diakses semua fungsi, dideklarasikan diluar fungsi apapun

// int nilai = 9; // variabel global

// int main()
// {
//     int nilai2 = 7; // variabel lokal

//     printf("cetak nilai %d %d",nilai,nilai2);
// }


// ---------------Pass by value dan Pass by reference
// pass by value adalah memberikan nilai pada parameter fungsi secara langsung contoh : jumlah_data(9);
// pass by reference adalah memberikan nilai nilai pada parameter dengan memeberi alamat contoh : jumlah_data(&data_kelas);


int kali_dua(int *angka) // menggunakan pointer karenaharus memberikan alamat
{
    *angka = *angka * 2; 
}

int main()
{
    int angka = 9;

    // memanggil fungsi kali dua

    kali_dua(&angka);

    printf("isi variabel angka = %d", angka);;
}