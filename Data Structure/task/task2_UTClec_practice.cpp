#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Customer
{
    char custName[100];
    char custMembership[100];
    struct Customer *left, *right;
} *custRoot = NULL;

struct Customer *createDataCust(char custName[], char custMembership[])
{
    struct Customer *temp = (struct Customer *)malloc(sizeof(struct Customer));
    strcpy(temp->custName, custName);
    strcpy(temp->custMembership, custMembership);
    temp->left = temp->right = 0;
    return temp;
}

struct Customer *insertDataCust(struct Customer *curr, struct Customer *custName)
{
    if (curr == 0)
    {
        return custName;
    }
    else if (strcmpi(custName->custName, curr->custName) < 0)
    {
        curr->left = insertDataCust(curr->left, custName);
    }
    else if (strcmpi(custName->custName, curr->custName) > 0)
    {
        curr->right = insertDataCust(curr->right, custName);
    }
    return curr;
}

struct Membership
{
    char membershipName[100];
    Membership *left, *right;
} *memberRoot;

struct Membership *creatData(char membershipName[])
{
    struct Membership *temp = (struct Membership *)malloc(sizeof(struct Membership));
    strcpy(temp->membershipName, membershipName);
    temp->left = temp->right = 0;
    return temp;
}

struct Membership *insertData(struct Membership *curr, struct Membership *data)
{
    if (curr == 0)
    {
        return data;
    }
    else if (strcmp(data->membershipName, curr->membershipName) < 0)
    {
        curr->left = insertData(curr->left, data);
    }
    else if (strcmp(data->membershipName, curr->membershipName) > 0)
    {
        curr->right = insertData(curr->right, data);
    }
    return curr;
}

int searchMembership(struct Membership *curr, char membershipName[])
{
    if (curr == 0)
    {
        return 0;
    }
    else if (strcmp(membershipName, curr->membershipName) == 0)
    {
        return 1;
    }
    else if (strcmp(membershipName, curr->membershipName) < 0)
    {
        return searchMembership(curr->left, membershipName);
    }
    else
    {
        return searchMembership(curr->right, membershipName);
    }
}

void searchCustomer(struct Customer *curr, char custName[], char custMembership[])
{
    if (curr == 0)
    {
        printf("Succesfully add customer\n");

        custRoot = insertDataCust(custRoot, createDataCust(custName, custMembership));
    }
    else if (strcmpi(custName, curr->custName) == 0)
    {
        printf("Customer already exists! Updated membership\n");
        strcpy(curr->custName, custName);
        strcpy(curr->custMembership, custMembership);
    }
    else if (strcmpi(custName, curr->custName) < 0)
    {
        return searchCustomer(curr->left, custName, custMembership);
    }
    else
    {
        return searchCustomer(curr->right, custName, custMembership);
    }
}
struct Customer *deleteCustomer(struct Customer *curr, char custName[])
{
    if (curr == 0)
    {
        printf("Customer not found\n");
        return 0;
    }
    else if (strcmpi(custName, curr->custName) < 0)
    {
        curr->left = deleteCustomer(curr->left, custName);
    }
    else if (strcmpi(custName, curr->custName) > 0)
    {
        curr->right = deleteCustomer(curr->right, custName);
    }
    else
    {
        if (curr->left == 0 && curr->right == 0)
        {
            free(curr);
            curr = 0;
            printf("Succesfully to delete\n");
        }
        else if (curr->left == 0)
        {
            struct Customer *temp = curr;
            curr = curr->right;
            free(temp);
            temp = 0;
            printf("Succesfully to delete\n");
        }
        else if (curr->right == 0)
        {
            struct Customer *temp = curr;
            curr = curr->left;
            free(temp);
            temp = 0;
            printf("Succesfully to delete\n");
        }
        else
        {
            struct Customer *temp = curr->left;
            while (temp->right != 0)
            {
                temp = temp->right;
            }
            strcpy(curr->custName, temp->custName);
            strcpy(curr->custMembership, temp->custMembership);
            curr->left = deleteCustomer(curr->left, temp->custName);
        }
    }
}

void displayMembership(struct Membership *curr)
{
    if (curr != 0)
    {
        displayMembership(curr->left);
        printf("- %s\n", curr->membershipName);
        displayMembership(curr->right);
    }
}

void displayCustomer(struct Customer *curr)
{
    if (custRoot == 0)
    {
        printf("There is no customer yet\n");
    }

    if (curr != 0)
    {
        displayCustomer(curr->left);
        printf("-%s (%s)\n", curr->custName, curr->custMembership);
        displayCustomer(curr->right);
    }
}

int main()
{
    memberRoot = insertData(memberRoot, creatData("Non Member"));
    memberRoot = insertData(memberRoot, creatData("Bronze"));
    memberRoot = insertData(memberRoot, creatData("Silver"));
    memberRoot = insertData(memberRoot, creatData("Gold"));
    memberRoot = insertData(memberRoot, creatData("Platinum"));

    int input = 0;
    char custName[100];
    char custMembership[100];
    int cekMembership = 0;

    printf("=================================\n");
    printf("Welocome to Hovs Fresh Concoction\n");
    printf("=================================\n");
    do
    {
        printf("What you want to do ?\n");
        printf("1. Add Customer\n");
        printf("2. View Customer\n");
        printf("3. Delete Customer\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &input);
        getchar();
        switch (input)
        {
        case 1:
            do
            {
                printf("input name (3-50 characthers): ");
                scanf("%s", custName);
                getchar();
            } while (strlen(custName) < 3 || strlen(custName) > 50);
            printf("Our Membership\n");
            printf("1. Non Member\n");
            printf("2. Bronze\n");
            printf("3. Silver\n");
            printf("4. Gold\n");
            printf("5. Platinum\n");
            do
            {
                printf("Type the membership (case sensitive) : ");
                scanf("%[^\n]", custMembership);
                getchar();
                cekMembership = searchMembership(memberRoot, custMembership);
                if (cekMembership == 0)
                {
                    printf("Membership not found, Write correctly the membership type\n");
                }
            } while (cekMembership == 0);
            searchCustomer(custRoot, custName, custMembership);

            break;
        case 2:
            displayCustomer(custRoot);
            break;
        case 3:
            do
            {
                printf("input name (3-50 characthers): ");
                scanf("%s", custName);
            } while (strlen(custName) < 3 || strlen(custName) > 50);
            custRoot = deleteCustomer(custRoot, custName);
            break;
        default:
            break;
        }
    } while (input != 4);
}