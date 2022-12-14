#include <stdio.h>


int main()
{
    int arr[200001]; 
    int T,n; 
    

    scanf("%d",&T); 

    for(int i =0; i<T; i++){ 
        int count =0, max = 0 , value =0, space = 0; 
        scanf("%d",&n); 

        for(int j = 0; j<200001; j++)arr[j] = 0;
        
        for(int u =0; u<n; u++){

            scanf("%d",&value);
            count = arr[value]; 
            count++;
            
            if(count > max){ 
                max = count;
            }
            arr[value] = count; 
        }
        printf("Case #%d: %d\n",i+1,max);
        for(int i = 0; i<200001; i++){ 
           
            if(arr[i] == max){ 
                printf("%s%d",space == 0 ? "":" ",i);
                space++;
            }
     
        }
        printf("\n");
        
    }
    

}