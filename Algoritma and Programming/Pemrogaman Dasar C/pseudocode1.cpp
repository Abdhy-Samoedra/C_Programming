#include <stdio.h>

int main()
{
    // no 1
    // int length,width;
    // printf("Input the length: ");
    // scanf("%d",&length);
    // printf("Input the width: ");
    // scanf("%d",&width);

    // printf("area of rectangle with length %d and width %d is : %d",length,width,length*width);
    

    //no 2
    // int hours,minute,second;
    // printf("masukkan detik = ");
    // scanf("%d",&second);


    // printf("%d jam %d menit %d detik ",second/3600,(second%3600)/60,second%60);

    //no 3
    // int number;
    // printf("input the number to check : ");
    // scanf("%d",&number);
    // if (number % 2 == 0)
    // {
    //     printf("Genap");
    // }else{
    //     printf("Ganjil");
    // }

    //no 4
    // int jariJari;
    // float pi = 3.14;
    // printf("Input the jari jari: ");
    // scanf("%d",&jariJari);
    // printf("area of circle  with jari jari %d is : %f",jariJari, pi*jariJari*jariJari);
    

    //no 5
    int num1,num2,num3;
    printf("Input the first number: ");
    scanf("%d",&num1);
    printf("Input the second number: ");
    scanf("%d",&num2);
    printf("Input the third number: ");
    scanf("%d",&num3);

    if ( num1 > num2 && num1 > num3)
    {
        printf("the first number \" %d \" is higher", num1);
    }else if ( num2 > num3)
    {
        printf("the second number \" %d \" is higher",num2);
    }else{
        printf("the third number \" %d \" is higher",num3);
    }
    
    
    
    return 0;
}