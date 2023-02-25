#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Student
{
    char name[100];
    char NIM[100];
    struct Student *left, *right;
} *root = NULL;

struct Student *createDataStudent(char name[], char NIM[])
{
    struct Student *temp = (struct Student *)malloc(sizeof(struct Student));
    strcpy(temp->name, name);
    strcpy(temp->NIM, NIM);
    temp->left = temp->right = 0;
    return temp;
}

struct Student *insertDataStudent(struct Student *curr, struct Student *name)
{
    if (curr == 0)
    {
        printf("Succesfully add Student\n");
        return name;
    }
    else if (strcmpi(name->name, curr->name) == 0)
    {
        printf("Student already exists! Updated Student\n");
        strcpy(curr->NIM, name->NIM);
    }
    else if (strcmpi(name->name, curr->name) < 0)
    {
        curr->left = insertDataStudent(curr->left, name);
    }
    else if (strcmpi(name->name, curr->name) > 0)
    {
        curr->right = insertDataStudent(curr->right, name);
    }
    return curr;
}

struct Student *deleteStudent(struct Student *curr, char name[])
{
    if (curr == 0)
    {
        printf("Student not found\n");
        return 0;
    }
    else if (strcmpi(name, curr->name) < 0)
    {
        curr->left = deleteStudent(curr->left, name);
    }
    else if (strcmpi(name, curr->name) > 0)
    {
        curr->right = deleteStudent(curr->right, name);
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
            struct Student *temp = curr;
            curr = curr->right;
            free(temp);
            temp = 0;
            printf("Succesfully to delete\n");
        }
        else if (curr->right == 0)
        {
            struct Student *temp = curr;
            curr = curr->left;
            free(temp);
            temp = 0;
            printf("Succesfully to delete\n");
        }
        else
        {
            struct Student *temp = curr->left;
            while (temp->right != 0)
            {
                temp = temp->right;
            }
            strcpy(curr->name, temp->name);
            strcpy(curr->NIM, temp->NIM);
            curr->left = deleteStudent(curr->left, temp->name);
        }
    }
}

void displayStudent(struct Student *curr)
{
    if (root == 0)
    {
        printf("There is no Student yet\n");
    }

    if (curr != 0)
    {
        displayStudent(curr->left);
        printf("-%s (%s)\n", curr->name, curr->NIM);
        displayStudent(curr->right);
    }
}

bool cekNIM(char NIM[])
{
    int length = strlen(NIM);
    for (int i = 0; i < length; i++)
    {
        if (NIM[i] < '0' || NIM[i] > '9')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int input = 0;
    char name[100];
    char NIM[100];
    bool cek;

    printf("=======================\n");
    printf("Welocome to the College\n");
    printf("=======================\n");
    do
    {
        printf("What you want to do ?\n");
        printf("1. Add Student\n");
        printf("2. View Student\n");
        printf("3. Delete Student\n");
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
                scanf("%[^\n]", name);
                getchar();
            } while (strlen(name) < 3 || strlen(name) > 50);
            do
            {
                printf("input NIM (8 characther): ");
                scanf("%s", NIM);
                getchar();
            } while (strlen(NIM) != 8 || cekNIM(NIM) == false);
            root = insertDataStudent(root, createDataStudent(name, NIM));

            break;
        case 2:
            displayStudent(root);
            break;
        case 3:
            do
            {
                printf("input name (3-50 characthers): ");
                scanf("%s", name);
            } while (strlen(name) < 3 || strlen(name) > 50);
            root = deleteStudent(root, name);
            break;
        default:
            break;
        }
    } while (input != 4);
}