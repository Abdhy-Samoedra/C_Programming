#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int number;
    char roman[100];
    printf("input the number to convert: ");
    scanf("%d",&number);

    switch (number)
    {
    case 1:
        strcpy(roman ,"I");
        break;
    case 2:
        strcpy(roman , "II");
        break;
    case 3:
        strcpy(roman , "III");
        break;
    case 4:
        strcpy(roman , "IV");
        break;
    case 5:
        strcpy(roman , "V");
        break;
    case 6:
        strcpy(roman , "VI");
        break;
    case 7:
        strcpy(roman , "VII");
        break;
    case 8:
        strcpy(roman , "VIII");
        break;
    case 9:
        strcpy(roman , "IX");
        break;
    case 10:
        strcpy(roman , "X");
        break;
    
    default:
        strcpy(roman , "error");
        break;
    }
    printf("angka romawi dari %d adalah %s",number,roman);

    // char color1[10];
    // char color2[10];

    // printf("input first color: ");
    // scanf("%s",color1);
    // printf("input second color: ");
    // scanf("%s",color2);

    // if (strcmp(color1, "red" )==0 && strcmp(color2, "blue")==0 ||strcmp(color1, "blue")==0 && strcmp(color2, "red")==0 )
    // {
    //     printf("Purple");
    // }else if (strcmp(color1, "red" )==0 && strcmp(color2, "yellow")==0 ||strcmp(color1, "yellow")==0 && strcmp(color2, "red")==0 )
    // {
    //     printf("Orange");
    // }else if (strcmp(color1, "yellow" )==0 && strcmp(color2, "blue")==0 ||strcmp(color1, "blue")==0 && strcmp(color2, "yellow")==0 )
    // {
    //     printf("Green");
    // }else
    // {
    //     printf("Not primary colors");
    // }
    
    
    





}