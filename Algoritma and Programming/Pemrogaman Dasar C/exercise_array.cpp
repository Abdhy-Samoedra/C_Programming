#include <stdio.h>

int main()
{

    // excercise 1
    int value[10];
    int total=0;
     for (int i = 0; i < 10; i++)
     {
        scanf("%d",&value[i]);
        total=total+value[i];
     }

     int max = value[0];
     int min = value[0];
     for (int i = 0; i < 10; i++)
     {
        printf("Value [%d] : %d\n",i,value[i]);

        if (value [i] >= max)
        {
            max = value [i];
        } if (value [i] <= min)
        {
            min = value [i];
        }
     }

     printf("max value = %d\n",max);
     printf("min value = %d\n",min);
     printf("average = %d\n",total/10);

    
     
     
}