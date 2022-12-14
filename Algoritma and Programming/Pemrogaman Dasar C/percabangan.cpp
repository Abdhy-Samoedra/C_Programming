#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // //PERCANBANGAN IF ELSE
    char password [20];
    printf("Masukkan password : ");
    scanf("%s",password);

    if (strcmp(password, "sayang")==0) //kenapa 0? karena pembanding akan bernilai 0 jika yang dibandingkan sama
    {
        puts("Selamat datang sayang");
    }else{
        puts("Kamu siapa ya?");
    }

    // PERCABANGAN IF ELSE IF

    // int nilai;
    // char grade;

    // printf("Masukkan nilai anda : ");
    // scanf("%d",&nilai);

    // if (nilai >= 90)
    // {
    //     grade = 'A';
    // }else if (nilai >= 80)
    // {
    //     grade = 'B';
    // }else if (nilai >= 70)
    // {
    //     grade = 'c';
    // }else{
    //     grade = 'f';
    // }
    // printf("%d",nilai);
    // printf("Grade anda : %c",grade);



    // PERCABANGAN SWITCH CASE
    // char grade;
    // printf("Inputkan grade = ");
    // scanf("%c", &grade);
    
    // switch (toupper(grade)) //toupper menggunakan library <ctype.h>
    // {
    // case 'A':
    //     printf("Luar biasa\n");
    //     break;
    // case 'B':
    // case 'C':
    //     printf("Bagus!\n");
    //     break;
    // case 'D':
    //     printf("Anda lulus\n");
    //     break;
    
    // default:
    //     printf("Remidi\n");
    //     break;
    // }

    // PERCABANGAN TERNARY

    // int hasil;
    
    // printf("Berapakah hasil dari 7 + 6?\n");
    // printf("Hasil = ");
    // scanf("%d", &hasil);

    // printf("Jawaban anda = %s\n", (hasil == 13) ? "Benar" : "Salah");
    
    // PERCABANGAN NESTED

    // char username [50];
    // char password [50];

    // printf("WELCOME\n");
    // printf("Username = ");
    // scanf("%s", &username);
    // printf("Password = ");
    // scanf("%s", &password);

    // if (strcmp(username,"abdhy") == 0)
    // {
    //     if (strcmp(password,"samoedra") == 0)
    //     {
    //         printf("Username dan password anda benar");
    //     }else{
    //         printf("Password anda salah");
    //     }
        
    // }else{
    //     printf("anda belum terdaftar");
    // }
    
    
    return 0 ;
}