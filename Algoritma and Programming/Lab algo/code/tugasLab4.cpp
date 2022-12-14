#include <stdio.h>
#include <string.h>


int main()
{
    int prices[20];
    char names [20][50];
    int input=0;

    //penanda terakhir isi sampai mama
    int last_index= 0;

    do
    {   
        for (int i = 0; i < last_index; i++)
        {
            printf("%s\n%d",names[i],prices[i]);
        }
        
        printf("1. Add item\n");
        printf("2. Exit\n");
        printf(">>");
        scanf("%d", &input);
        getchar();

        switch (input)
        {
        case 1:
            //ambil input item name
            char name[50];
            printf("input item name: ");
            scanf("%[^\n]",name);

            //ambil input item price
            int price;
            printf("input item price: ");
            scanf("%[^\n]",&price);
            

            //masukkin item name dan price kedalam array
            prices[last_index] = price;
            strcpy(names[last_index], name);
            last_index++;
            break;
        case 2:
            /* code */
            break;
        
        default:
            break;
        }
    } while (input != 2);
    
}