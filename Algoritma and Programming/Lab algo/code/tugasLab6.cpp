#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    system("cls");
    int input;
    int update;
    int sell;
    int index = 0;
    int cekdigit = 0;
    double itemPrice;
    char itemId[100];
    char itemName[100];
    char insertId[100][255];
    char insertName[100][255];
    double insertPrice[100];

    do
    {
        puts("Electronics!");
        puts("=================");
        puts("1. Insert ELectronic Stock");
        puts("2. Update Electronic");
        puts("3. Sell Electronic");
        puts("4. Exit");
        printf(">> ");
        scanf("%d", &input);
        getchar();

        if (input == 1)
        {
            do
            {
                cekdigit = 0;
                printf("Input item Id [must be numeric with exactly 3 digits]: ");
                scanf("%s", itemId);
                getchar();
                for (int i = 0; i < strlen(itemId); i++)
                {
                    if (isdigit(itemId[i]) == 0)
                    {
                        cekdigit = 1;
                    }
                }
            } while (strlen(itemId) != 3 || cekdigit == 1);

            do
            {
                printf("Input item name [5-25 character]: ");
                scanf("%[^\n]", itemName);
                getchar();
            } while (strlen(itemName) < 6 || strlen(itemName) > 24);
            do
            {
                printf("Input item price [not more than 5M]: ");
                scanf("%lf", &itemPrice);
                getchar();
            } while (itemPrice > 5000000);

            strcpy(insertId[index], itemId);
            strcpy(insertName[index], itemName);
            insertPrice[index] = itemPrice;
            index++;

            printf("Item succesfully inserted!\n");
            printf("Press enter to continue...");
            getchar();
            system("cls");
        }

        if (input == 2)
        {
            if (index == 0)
            {
                printf("There is no item yet...\n");
                printf("Press enter to continue...");
                getchar();
                system("cls");
            }
            if (index != 0)
            {
                printf("=================================================================================\n");
                printf("| No.\t| Id\t| Name\t\t\t\t| Price\t\t\t\t|\n");
                for (int j = 0; j < index; j++)
                {
                    printf("=================================================================================\n");
                    printf("| %d\t| ETC%s| %s\t\t| %.2lf\t\t\t|\n", j + 1, insertId[j], insertName[j], insertPrice[j]);
                }
                printf("=================================================================================\n");

                do
                {
                    printf("Which item you want to update? [0 to exit] [1...%d]: ", index);
                    scanf("%d", &update);
                    getchar();
                    if (update == 0)
                    {
                        break;
                    }

                } while (update < 1 || update > index);

                do
                {
                    if (update == 0)
                    {
                        break;
                    }
                    cekdigit = 0;
                    printf("Input item Id [must be numeric with exactly 3 digits]: ");
                    scanf("%s", itemId);
                    getchar();
                    for (int i = 0; i < strlen(itemId); i++)
                    {
                        if (isdigit(itemId[i]) == 0)
                        {
                            cekdigit = 1;
                        }
                    }
                } while (strlen(itemId) != 3 || cekdigit == 1);

                do
                {
                    if (update == 0)
                    {
                        break;
                    }
                    printf("Input item name [5-25 character]: ");
                    scanf("%[^\n]", itemName);
                    getchar();
                } while (strlen(itemName) < 6 || strlen(itemName) > 24);
                do
                {
                    if (update == 0)
                    {
                        break;
                    }
                    printf("Input item price [not more than 5M]: ");
                    scanf("%lf", &itemPrice);
                    getchar();
                } while (itemPrice > 5000000);
                if (update != 0)
                {
                    strcpy(insertId[update - 1], itemId);
                    strcpy(insertName[update - 1], itemName);
                    insertPrice[update - 1] = itemPrice;

                    printf("Item succesfully updated!\n");
                    printf("Press enter to continue...");
                    getchar();

                    system("cls");
                }
            }
        }

        if (input == 3)
        {
            if (index == 0)
            {
                printf("There is no item yet...\n");
                printf("Press enter to continue...");
                getchar();
                system("cls");
            }
            if (index != 0)
            {
                printf("=================================================================================\n");
                printf("| No.\t| Id\t| Name\t\t\t\t| Price\t\t\t\t|\n");
                for (int j = 0; j < index; j++)
                {
                    printf("=================================================================================\n");
                    printf("| %d\t| ETC%s| %s\t\t| %.2lf\t\t\t|\n", j + 1, insertId[j], insertName[j], insertPrice[j]);
                }
                printf("=================================================================================\n");

                do
                {
                    printf("Which item you want to sell [0 to exit] [1...%d]: ", index);
                    scanf("%d", &sell);
                    getchar();
                    if (sell == 0)
                    {
                        break;
                    }

                } while (sell < 1 || sell > index);

                if (sell != 0)
                {
                    srand(time(0));
                    if (rand() % 11 < 3)
                    {
                        printf("#########################\n");
                        printf("Customer get discount 25%\n");
                        printf("#########################\n");
                        printf("\n");
                        printf("ETC%s Item Detail\n", insertId[sell - 1]);
                        printf("=======================\n");
                        printf("Item Name : %s\n", insertName[sell - 1]);
                        printf("Item Price : %lf\n", insertPrice[sell - 1] - insertPrice[sell - 1] * 0.25);
                    }
                    else
                    {
                        printf("ETC%s Item Detail\n", insertId[sell - 1]);
                        printf("=======================\n");
                        printf("Item Name : %s\n", insertName[sell - 1]);
                        printf("Item Price : %lf\n", insertPrice[sell - 1]);
                    }
                }
                else
                {
                    break;
                }
                if (sell != 0)
                {
                    int yes, no;
                    char yatidak[100];
                    do
                    {
                        printf("Are you sure you want to sell this? [yes|no]: ");
                        scanf("%s", yatidak);
                        getchar();
                        yes = strcmp("yes", yatidak);
                        no = strcmp("no", yatidak);

                    } while (yes != 0 && no != 0);

                    if (yes == 0)
                    {
                        for (int k = sell - 1; k < index; k++)
                        {
                            strcpy(insertId[k], insertId[k + 1]);
                            strcpy(insertName[k], insertName[k + 1]);
                            insertPrice[k] = insertPrice[k + 1];
                        }
                        index--;
                        printf("Item succesfully sold!\n");
                        printf("Press enter to continue...");
                        getchar();

                        system("cls");
                    }
                    else if (no == 0)
                    {
                        printf("Cancel selling!\n");
                        printf("Press enter to continue...");
                        getchar();

                        system("cls");
                    }
                }
            }
        }

    } while (input != 4);
}