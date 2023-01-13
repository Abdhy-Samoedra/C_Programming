#include <stdio.h>
#include <string.h>

struct pc
{
    char motherBoard[30];
    char processor[30];
    char VGA[30];
    int RAM;
    double price;
} pcArr[30];

int currentCount = 0;

void dummy(char motherBoard[], char processor[], char VGA[], int RAM, double price)
{
    strcpy(pcArr[currentCount].motherBoard, motherBoard);
    strcpy(pcArr[currentCount].processor, processor);
    strcpy(pcArr[currentCount].VGA, VGA);
    pcArr[currentCount].RAM = RAM;
    pcArr[currentCount].price = price;

    currentCount++;
}
  
void displayData()
{
    if (currentCount == 0)
    {
        printf("There is no Data in here\n");
    }
    else
    {
        for (int i = 0; i < currentCount; i++)
        {
            printf("%d %-30s %-30s %-30s %-4d %-10.2lf\n", i + 1, pcArr[i].motherBoard, pcArr[i].processor, pcArr[i].VGA, pcArr[i].RAM, pcArr[i].price);
        }
    }
}
void modifyData()
{
    if (currentCount == 0)
    {
        printf("There is no Data in here\n");
    }

    displayData();

    int num;
    char motherBoard[30];
    char processor[30];
    char VGA[30];
    int RAM;
    double price;
    printf("input nomer yang mau di modif: ");
    scanf("%d", &num);
    getchar();

    do
    {
        printf("Enter Motherboard : ");
        scanf("%[^\n]", motherBoard);
        getchar();

        printf("Enter processor : ");
        scanf("%[^\n]", processor);
        getchar();

        printf("Enter VGA : ");
        scanf("%[^\n]", VGA);
        getchar();

        printf("Enter RAM : ");
        scanf("%d", &RAM);
        getchar();

        printf("Enter Price : ");
        scanf("%lf", &price);
        getchar();

        strcpy(pcArr[num - 1].motherBoard, motherBoard);
        strcpy(pcArr[num - 1].processor, processor);
        strcpy(pcArr[num - 1].VGA, VGA);
        pcArr[num - 1].RAM = RAM;
        pcArr[num - 1].price = price;

    } while (num < 1 || num > currentCount);
}
void insertData()
{
    char motherBoard[30];
    char processor[30];
    char VGA[30];
    int RAM;
    double price;

    printf("Enter Motherboard : ");
    scanf("%[^\n]", motherBoard);
    getchar();

    printf("Enter processor : ");
    scanf("%[^\n]", processor);
    getchar();

    printf("Enter VGA : ");
    scanf("%[^\n]", VGA);
    getchar();

    printf("Enter RAM : ");
    scanf("%d", &RAM);
    getchar();

    printf("Enter Price : ");
    scanf("%lf", &price);
    getchar();

    strcpy(pcArr[currentCount].motherBoard, motherBoard);
    strcpy(pcArr[currentCount].processor, processor);
    strcpy(pcArr[currentCount].VGA, VGA);
    pcArr[currentCount].RAM = RAM;
    pcArr[currentCount].price = price;

    currentCount++;
}

int main()
{
    int input;
    dummy("asus tuf gaming", "core i8", "rtx 1080ti", 34, 8000000);
    dummy("acer tuf gaming", "core i8", "rtx 1080ti", 34, 8000000);
    dummy("lenovo tuf gaming", "core i8", "rtx 1080ti", 34, 8000000);

    do
    {
        puts("1. Display PC Data");
        puts("2. Insert PC Data");
        puts("3. Modify PC Data");
        puts("4. Delete PC Data");
        puts("5. Exit");
        printf(">> ");

        scanf("%d", &input);
        getchar();

        switch (input)
        {
        case 1:
            displayData();
            break;
        case 2:
            insertData();
            break;
        case 3:
            modifyData();
            break;
        case 4:

            break;
        }
    } while (input != 5);
}