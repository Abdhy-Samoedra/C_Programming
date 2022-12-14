#include <stdio.h>
#define MAX  15
int main()
{
    // char buf[MAX];
    // fgets(buf, MAX, stdin);
    // printf("string is: %s\n", buf);
  
    // return 0;
    


    // char nama[MAX];

    // printf("Berikan nama Anda: ");
    
    // fgets(nama, MAX, stdin);
 
    // //Asumsi saya memberikan "Hendro Sinaga"

    // printf("Hi %s, selamat datang. \0", nama);
    // /*Maka, program akan menampilkan:
    //   Hi Hendro Sinaga
    //   , selamat datang.
    // */

    // return 0;


    char nama[20];
    short indeks = 0;

    printf("Berikan nama Anda: ");
    fgets(nama, sizeof(nama), stdin);

    //Asumsi saya memberikan "Hendro Sinaga"

    while(1) {
        if(nama[indeks] == '\n'){
            nama[indeks] = '\0';
            break;
        }
        indeks += 1;
    }

    printf("Hi %s, selamat datang.\n", nama);
    /*Maka, program akan menampilkan:
      Hi Hendro Sinaga, selamat datang.
    */

    return 0;
  //Program sudah berjalan dengan benar.. :D
  


  

}


