#include <stdio.h>

int main()
{

    // no1
    // int a = 1;
    // while (a*5 <= 100)
    // {
    //     printf("%d ",a*5);
    //     a++;
    // }

    // // // no 2
    // int input;
    // int angka = 0;
    // int jumlah = 0;
    // printf("Input the end point: ");
    // scanf("%d",&input);

    // while (angka <= input)
    // {
    //     angka = angka+2;
    //     jumlah++;
        
    // } 
    // printf("%d",jumlah);
    

    //no 3
    // int sum = 0;
    // int number;
    // printf("input the number: ");
    // scanf("%d",&number);
    // while (number >= 0)
    // {
    //     sum = sum + number;
    //     printf("input the number: ");
    //     scanf("%d",&number);
    // }
    // printf("%d",sum );

    //no 4
    // int input;
    // int a = 1;
    // int b = 1;
    // int next;
    // printf("Input the end point: ");
    // scanf("%d",&input);

    // while (a <= input)
    // {
    //     printf("%d ",a);
    //     next = a+b;
    //     a = b;
    //     // 
    //     b = next;
    // } 
    

    // no 5
    int number[5];
    float avg;

    for (int i = 0; i < 5; i++)
    {
        printf("input the number: ");
        scanf("%d",&number[i]);
        avg += number[i];
    }

    avg = avg/5;
    
    printf("Average from the numbers = %.2f\n",avg);

    if (   (number[0] > number[1] && number[0] > number[2])  &&  (number[0] > number[3] && number[0] > number[4])  )
    {
        printf("Maximum number = %d\n",number[0]);
    }else if (   (number[1] > number[2]  &&  number[1] > number[3] ) &&  number[1] > number[4]  )
    {
        printf("Maximum number = %d\n",number[1]);
    }else if (   number[2] > number[3]   &&   number[2] > number[4]  )
    {
        printf("Maximum number = %d\n",number[2]);
    }else if (  number[3] > number[4]   )
    {
        printf("Maximum number = %d\n",number[3]);
    }else
    {
        printf("Maximum number = %d\n",number[4]);
    }
    

    if (   (number[0] < number[1] && number[0] < number[2])  &&  (number[0] < number[3] && number[0] < number[4])  )
    {
        printf("Minimum number = %d",number[0]);
    }else if (   (number[1] < number[2]  &&  number[1] < number[3] ) &&  number[1]< number[4]  )
    {
        printf("Minimum number = %d",number[1]);
    }else if (   number[2] < number[3]   &&   number[2] <number[4]  )
    {
        printf("Minimum number = %d",number[2]);
    }else if (  number[3] < number[4]   )
    {
        printf("Minimum number = %d",number[3]);
    }else
    {
        printf("Minimum number = %d",number[4]);
    }
    

     
   
    
    
}