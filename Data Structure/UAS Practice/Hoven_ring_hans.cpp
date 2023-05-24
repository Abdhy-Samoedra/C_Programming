#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int counter = 1;
int found = 0;
int cutChain = 0;

struct Player
{
    char username[100];
    int score;
    char job[20];
    int matchCount;
    int winCount;
    int loseCount;
    int drawCount;
    double winRate;
    int height;
    Player *left, *right, *next;
} *root = NULL;

int getHeight(Player *curr)
{
    if (curr == NULL)
    {
        return 0;
    }
    int left = getHeight(curr->left);
    int right = getHeight(curr->right);
    if (left > right)
    {
        return left + 1;
    }
    else
    {
        return right + 1;
    }
}

int getBF(Player *curr)
{
    if (curr == NULL)
    {
        return 0;
    }
    return getHeight(curr->left) - getHeight(curr->right);
}

Player *rotateRight(Player *root)
{
    Player *lc = root->left;
    Player *rc = root->right;
    Player *lrc = lc->right;

    lc->right = root;
    root->left = lrc;

    lc->height = getHeight(lc);
    root->height = getHeight(root);

    return lc;
}

Player *rotateLeft(Player *root)
{
    Player *lc = root->left;
    Player *rc = root->right;
    Player *rlc = rc->left;

    rc->left = root;
    root->right = rlc;

    rc->height = getHeight(lc);
    root->height = getHeight(root);

    return rc;
}

Player *createPlayer(const char username[], const char job[], int score, int matchCount, int winCount, int loseCount, int drawCount)
{
    Player *newPlayer = (Player *)malloc(sizeof(Player));
    strcpy(newPlayer->username, username);
    newPlayer->score = score;
    strcpy(newPlayer->job, job);
    newPlayer->matchCount = matchCount;
    newPlayer->winCount = winCount;
    newPlayer->loseCount = loseCount;
    newPlayer->drawCount = drawCount;
    newPlayer->winRate = ((double)winCount / (double)matchCount) * 100.00;
    newPlayer->left = newPlayer->right = newPlayer->next = NULL;
    newPlayer->height = 0;

    return newPlayer;
}

Player *pushCollision(Player *curr, Player *newPlayer)
{
    Player *temp = curr;
    if (newPlayer->winRate > curr->winRate)
    {
        newPlayer->left = curr->left;
        newPlayer->right = curr->right;
        newPlayer->next = temp;
        curr = newPlayer;
        return curr;
    }

    while (temp->next != NULL && newPlayer->winRate <= temp->next->winRate)
    {
        if (temp->next == NULL)
        {
            break;
        }
        temp = temp->next;
    }
    newPlayer->next = temp->next;
    temp->next = newPlayer;
    return curr;
}

Player *insertPlayer(Player *curr, Player *newPlayer)
{
    if (curr == NULL)
    {
        return newPlayer;
    }
    else if (newPlayer->score < curr->score)
    {
        curr->left = insertPlayer(curr->left, newPlayer);
    }
    else if (newPlayer->score > curr->score)
    {
        curr->right = insertPlayer(curr->right, newPlayer);
    }
    else
    {
        curr = pushCollision(curr, newPlayer);
    }

    curr->height = getHeight(curr);
    int BF = getBF(curr);

    if (BF > 1)
    {
        if (getBF(curr->left) < 0)
        {
            curr->left = rotateLeft(curr->left);
        }

        return rotateRight(curr);
    }
    else if (BF < -1)
    {
        if (getBF(curr->right) > 0)
        {
            curr->right = rotateRight(curr->right);
        }

        return rotateLeft(curr);
    }

    return curr;
}

Player *deletePlayer(Player *curr, int score)
{
    if (curr == NULL)
    {
        return curr;
    }
    else if (score < curr->score)
    {
        curr->left = deletePlayer(curr->left, score);
    }
    else if (score > curr->score)
    {
        curr->right = deletePlayer(curr->right, score);
    }
    else
    {
        if (curr->next != NULL)
        {
            if (cutChain == 1)
            {
                curr->next = NULL;
                free(curr);
                curr = NULL;
            }
            else
            {
                Player *del = curr;
                curr = curr->next;
                curr->left = del->left;
                curr->right = del->right;
                free(del);
            }
        }
        else
        {
            if (curr->left == NULL && curr->right == NULL)
            {
                free(curr);
                curr = NULL;
            }
            else if (curr->left == NULL)
            {
                Player *del = curr;
                curr = curr->right;
                free(del);
                del = NULL;
            }
            else if (curr->right == NULL)
            {
                Player *del = curr;
                curr = curr->left;
                free(del);
                del = NULL;
            }
            else
            {
                cutChain = 1;
                Player *temp = curr->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }

                strcpy(curr->username, temp->username);
                curr->score = temp->score;
                strcpy(curr->job, temp->job);
                curr->matchCount = temp->matchCount;
                curr->winCount = temp->winCount;
                curr->loseCount = temp->loseCount;
                curr->drawCount = temp->drawCount;
                curr->winRate = temp->winRate;
                curr->next = temp->next;

                curr->right = deletePlayer(curr->right, temp->score);
            }
        }
    }

    if (curr == NULL)
    {
        return curr;
    }

    curr->height = getHeight(curr);
    int BF = getBF(curr);

    if (BF > 1)
    {
        if (getBF(curr->left) < 0)
        {
            curr->left = rotateLeft(curr->left);
        }

        return rotateRight(curr);
    }
    else if (BF < -1)
    {
        if (getBF(curr->right) > 0)
        {
            curr->right = rotateRight(curr->right);
        }

        return rotateLeft(curr);
    }

    return curr;
}

void showTree(Player *curr)
{
    if (curr == NULL)
    {
        return;
    }
    showTree(curr->left);
    Player *temp = curr;
    printf("Score %d\n", curr->score);
    counter = 1;
    while (temp != NULL)
    {
        printf("%d. %s [%s] (%.0f%)\n", counter++, temp->username, temp->job, temp->winRate);
        temp = temp->next;
    }
    printf("\n");
    showTree(curr->right);
}

void findPlayer(Player *curr, int score)
{
    if (curr == NULL)
    {
        return;
    }
    findPlayer(curr->left, score);
    if (curr->score == score)
    {
        found = 1;
        Player *temp = curr;
        printf("Score %d\n", curr->score);
        counter = 1;
        while (temp != NULL)
        {
            printf("%d. %s [%s] (%.0f%)\n", counter++, temp->username, temp->job, temp->winRate);
            temp = temp->next;
        }
    }
    printf("\n");
    findPlayer(curr->right, score);
}

int main()
{
    root = insertPlayer(root, createPlayer("Gregor", "Sniper", 113, 10, 9, 1, 0));
    root = insertPlayer(root, createPlayer("Heimdall", "Druid", 300, 100, 50, 50, 0));
    root = insertPlayer(root, createPlayer("Travy", "Warrior", 300, 200, 100, 100, 0));
    root = insertPlayer(root, createPlayer("Tetron", "Novice", 300, 50, 25, 25, 0));
    root = insertPlayer(root, createPlayer("Homer", "Druid", 113, 10, 8, 2, 0));
    root = insertPlayer(root, createPlayer("Garen", "Warrior", 113, 100, 70, 30, 0));
    // root = insertPlayer(root, createPlayer("tes 2", "Warrior", 113, 100, 60, 30, 0));
    // root = insertPlayer(root, createPlayer("Tes", "Warrior", 113, 100, 70, 30, 0));
    // root = insertPlayer(root, createPlayer("tes 3", "Warrior", 112, 100, 70, 30, 0));
    // root = insertPlayer(root, createPlayer("tes 4", "Warrior", 111, 100, 70, 30, 0));
    // root = insertPlayer(root, createPlayer("tes 5", "Warrior", 110, 100, 70, 30, 0));
    // root = insertPlayer(root, createPlayer("tes 6", "Warrior", 2, 100, 70, 30, 0));
    // root = insertPlayer(root, createPlayer("tes 7", "Warrior", 3, 100, 70, 30, 0));
    // root = insertPlayer(root, createPlayer("tes 8", "Warrior", 4, 100, 70, 30, 0));
    // root = insertPlayer(root, createPlayer("tes 9", "Warrior", 5, 100, 70, 30, 0));
    // root = insertPlayer(root, createPlayer("tes 10", "Warrior", 6, 100, 70, 30, 0));
    // root = insertPlayer(root, createPlayer("tes 11", "Warrior", 6, 100, 80, 20, 0));

    int commandTimes = 0;
    scanf("%d", &commandTimes);
    getchar();

    for (int i = 0; i < commandTimes; i++)
    {
        char command[30] = {};
        scanf("%s", command);
        getchar();

        if (strcmpi(command, "INSERT") == 0)
        {
            int insertTimes = 0;
            scanf("%d", &insertTimes);
            getchar();

            for (int j = 0; j < insertTimes; j++)
            {
                char username[100];
                int jobCode;
                char job[20];
                int score;
                int matchCount;
                int winCount;
                int loseCount;
                int drawCount;

                scanf("%[^#]#%d#%d#%d#%d#%d#%d", username, &jobCode, &score, &matchCount, &winCount, &loseCount, &drawCount);
                if (jobCode == 0)
                {
                    strcpy(job, "Novice");
                }
                else if (jobCode == 1)
                {
                    strcpy(job, "Warrior");
                }
                else if (jobCode == 2)
                {
                    strcpy(job, "Sniper");
                }
                else if (jobCode == 3)
                {
                    strcpy(job, "Wizard");
                }
                else if (jobCode == 4)
                {
                    strcpy(job, "Druid");
                }
                else if (jobCode == 5)
                {
                    strcpy(job, "Assassin");
                }
                getchar();

                root = insertPlayer(root, createPlayer(username, job, score, matchCount, winCount, loseCount, drawCount));
            }
        }
        else if (strcmpi(command, "FIND") == 0)
        {
            found = 0;
            int score = 0;
            scanf("%d", &score);
            getchar();

            findPlayer(root, score);
            if (found == 0)
            {
                printf("Score %d\n", score);
                printf("No data found for %d\n", score);
            }
        }
        else if (strcmpi(command, "DELETE") == 0)
        {
            cutChain = 0;
            int score = 0;
            scanf("%d", &score);
            getchar();

            root = deletePlayer(root, score);
        }
        else if (strcmpi(command, "SHOWALL") == 0)
        {
            showTree(root);
            printf("\n");
        }
    }
}