#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Game
{
    char name[100];
    int rating;
    int hours;
    struct Game *left, *right;
} *root = 0;
struct GameQueue
{
    char name[100];
    int rating;
    int hours;
    struct GameQueue *next;
} *head = 0,*tail=0;
struct GameQueue *createRate(char name[], int rating, int hours)
{
    struct GameQueue *temp = (struct GameQueue *)malloc(sizeof(struct GameQueue));
    strcpy(temp->name, name);
    temp->hours = hours;
    temp->rating = rating;
    temp->next = 0;
    return temp;
}
struct Game *createGame(char name[], int rating, int hours)
{
    struct Game *temp = (struct Game *)malloc(sizeof(struct Game));
    strcpy(temp->name, name);
    temp->hours = hours;
    temp->rating = rating;
    temp->left = temp->right = 0;
    return temp;
}
void insertLinkdeList(char name[], int rating, int hours)
{
    struct GameQueue *temp = createRate(name, rating, hours);

    if (head == NULL && tail == NULL)
    {
        head = tail = temp;
    }
    else if (rating > head->rating)
    {
        // insert head
        temp->next = head;
        head = temp;
    }
    else if (rating <= tail->rating)
    {
        tail->next = temp;
        tail = temp;
    }
    else
    {
        struct GameQueue *curr = head;
        while (curr->next != NULL && curr->next->rating >= rating)
        {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}
void pop(char name[])
{
    struct GameQueue *del = head;
    if (head == NULL && tail == NULL)
    {
        printf("Queues are empty...\n");
        return;
    }
    else if (strcmpi(name, head->name) == 0)
    {
        GameQueue *temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
        if (head == NULL)
            tail = NULL;
    }
    else
    {
        GameQueue *curr = head;
        while (curr->next != NULL && strcmpi(name, curr->next->name) != 0)
        {
            curr = curr->next;
        }
        if (curr->next != NULL)
        {
            GameQueue *temp = curr->next;
            curr->next = temp->next;
            free(temp);
            temp = NULL;
            if (curr->next == NULL)
            {
                tail = curr;
            }
        }
    }
}
struct Game *insertGame(struct Game *curr, struct Game *newGame)
{
    if (curr == 0)
    {
        printf("Succesfully add Game\n");
        return newGame;
    }
    else if (strcmpi(newGame->name, curr->name) == 0)
    {
        printf("Game already exists! Updated Rating\n");
        curr->rating = newGame->rating;
        curr->hours = newGame->hours;
        pop(newGame->name);
    }
    else if (strcmpi(newGame->name, curr->name) > 0)
    {
        curr->left = insertGame(curr->left, newGame);
    }
    else if (strcmpi(newGame->name, curr->name) < 0)
    {
        curr->right = insertGame(curr->right, newGame);
    }
    return curr;
}

struct Game *deleteGame(struct Game *curr, char name[])
{
    if (curr == 0)
    {
        printf("Game not found\n");
        return 0;
    }
    else if (strcmpi(name, curr->name) > 0)
    {
        curr->left = deleteGame(curr->left, name);
    }
    else if (strcmpi(name, curr->name) < 0)
    {
        curr->right = deleteGame(curr->right, name);
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
            struct Game *temp = curr;
            curr = curr->right;
            free(temp);
            temp = 0;
            printf("Succesfully to delete\n");
        }
        else if (curr->right == 0)
        {
            struct Game *temp = curr;
            curr = curr->left;
            free(temp);
            temp = 0;
            printf("Succesfully to delete\n");
        }
        else
        {
            struct Game *temp = curr->left;
            while (temp->right != 0)
            {
                temp = temp->right;
            }
            strcpy(curr->name, temp->name);
            curr->rating = temp->rating;
            curr->hours = temp->hours;
            curr->left = deleteGame(curr->left, temp->name);
        }
    }
    return curr;
}

void displayRating()
{
    struct GameQueue *curr = head;
    while (curr != 0)
    {
        printf("-%s (%d)-(%d)\n", curr->name, curr->rating, curr->hours);
        curr = curr->next;
    }
}
void displayGame(struct Game *curr)
{
    if (root == 0)
    {
        printf("There is no Game yet\n");
    }

    if (curr != 0)
    {
        displayGame(curr->left);
        printf("-%s (%d)-(%d)\n", curr->name, curr->rating, curr->hours);
        displayGame(curr->right);
    }
}
void menu()
{
    int input = 0;
    char name[100];
    char nameToDel[100];
    char hours[100];
    char rating[100];
    int hoursInt;
    int ratingInt;
    int count = 0;
    do
    {
        printf("============================\n");
        displayGame(root);
        printf("============================\n");
        printf("\n");
        printf("1. insert Game\n");
        printf("2. delete Game\n");
        printf("3. View Game by rating\n");
        printf("4. exit\n");
        printf(">> ");
        scanf("%d", &input);
        getchar();
        switch (input)
        {
        case 1:
            do
            {
                count = 0;
                printf("input game name : ");
                scanf("%[^\n]", name);
                getchar();
                for (int i = 0; i < strlen(name); i++)
                {
                    if (isalnum(name[i]) == 0 && name[i] != ' ')
                    {
                        count++;
                    }
                }

            } while (strlen(name) < 1 || strlen(name) > 100 || count > 0);
            do
            {
                count = 0;
                printf("input rating : ");
                scanf("%s", rating);
                getchar();
                for (int i = 0; i < strlen(rating); i++)
                {
                    if (isdigit(rating[i]) == 0)
                    {
                        count++;
                    }
                }
                ratingInt = atoi(rating);

            } while (ratingInt < 1 || ratingInt > 10 || count > 0);
            do
            {
                count = 0;
                printf("input Hours : ");
                scanf("%s", hours);
                getchar();
                for (int i = 0; i < strlen(hours); i++)
                {
                    if (isdigit(hours[i]) == 0)
                    {
                        count++;
                    }
                }
                hoursInt = atoi(hours);

            } while (hoursInt < 0 || hoursInt > 2000 || count > 0);
            root = insertGame(root, createGame(name, ratingInt, hoursInt));
            insertLinkdeList(name, ratingInt, hoursInt);
            break;
        case 2:
            do
            {
                printf("============================\n");
                displayGame(root);
                printf("============================\n");
                count = 0;
                printf("input game name to delete : ");
                scanf("%[^\n]", nameToDel);
                getchar();
                for (int i = 0; i < strlen(nameToDel); i++)
                {
                    if (isalnum(nameToDel[i]) == 0 && nameToDel[i] != ' ')
                    {
                        count++;
                    }
                }

            } while (strlen(nameToDel) < 1 || strlen(nameToDel) > 100 || count > 0);
            root = deleteGame(root, nameToDel);
            pop(nameToDel);
            break;
        case 3:
            displayRating();
            break;

        default:
            break;
        }
    } while (input != 4);
}

int main()
{
    menu();
}