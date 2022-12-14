#include <stdio.h>

int main()
{

    // no 1
    // int sum = 0;
    // int number;
    // // printf("input the number: ");
    // // scanf("%d",&number);
    // while (number >= 0)
    // {
    //     sum = sum + number;
    //     // printf("input the number: ");
    //     scanf("%d",&number);
    // }
    // printf("%d",sum );

    // no2
    int number,smallest,largest;

    while (number != -99)
    {
        printf("input a number: ");
        scanf("%d",&number);
        
        if (number != -99)
        {
            if (number > largest)
            {
                largest = number;
            }else if (number < smallest)
            {

                smallest = number;

            }
            
                
        }
    } 
    
    printf("%d\n",largest);
    printf("%d",smallest);
    

    }
    
