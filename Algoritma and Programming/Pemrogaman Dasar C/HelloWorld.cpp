#include<stdio.h>

int main(){
    
    // char hello[] = "hello";
    // printf("%s", hello);
    
    // char huruf[12];

    // // regex
    // scanf("%[^\n]s",&huruf);

    // printf("%s",huruf);
    

    // char nama[12], pertanyaan[30] = "siapa nama kamu?";

    // scanf("%[^\n]s",nama);

    // printf("%s",nama);
    // printf("%s", pertanyaan);

    // char pertanyaan[30] = "Siapa nama kamu?", nama[20];
    // printf("%s\n", pertanyaan);
    // scanf("%[^\n]s",nama);
    // printf("nama kamu adalah %s", nama);


    char nama[30];
    puts("Siapa nama kamu?");
    scanf("%[^\n]s",nama);
    printf("Nama kamu adalah %s", nama);


}