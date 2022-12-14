#include <stdio.h>
#include <string.h>

char userIds[5][225] =
    {
        "christ0208",
        "jordywa",
        "haku",
        "elior",
        "cleo"};
char names[5][225] =
    {
        "Christoper",
        "Jordy",
        "Haku",
        "Eleanor",
        "Cleo Deus"};
char email[5][225] =
    {
        "chris@gmail.com",
        "jordy@gmail.com",
        "haku@gmail.com",
        "el@gmail.com",
        "cleo@gmail.com"};

int friendlist[5];
int friendcount = 0;
int resultindex[5];

int main()
{
    int input;
    // int resultCount;
    do
    {
        puts("Friendster CLI");
        puts("==========");
        puts("1. Add Friend");
        puts("2. Unfriend");
        puts("3. Exit");
        printf(">> ");
        scanf("%d", &input);
        getchar();

        if (input == 1)
        {
            char keyword[255];
            printf("Input your keyword: ");
            scanf("%[^\n]", keyword);
            getchar();
            int resultCount = 0;

            // ukuran data lima
            for (int i = 0; i < 5; i++)
            {
                // strcmpi kasus incasesensitif
                // strstr mencari suatu kata jika diketahui hurufnya saja
                // char tolower(char userIds);
                // char tolower(char keyword);
                if (strcmpi(userIds[i], keyword) == 0 || strstr(strlwr(names[i]), strlwr(keyword)) != NULL)
                {
                    resultindex[resultCount] = i;
                    resultCount++;
                    printf("%d. %s | %s | %s \n", resultCount, userIds[i], names[i], email[i]);
                    
                }
            }
            if (resultCount == 1)
            {
                char yn[4];
                printf("Do you want to add this friend? [yes|no]: ");
                scanf("%s", yn);
                getchar();

                if (strcmp("yes", yn) == 0)
                {
                    friendlist[friendcount] = resultindex[0];
                    friendcount++;
                }
            }
            if (resultCount > 1)
            {
                int coiche = 0;
                printf("input the number you want to add [0 to exit] : ");
                scanf("%d", &coiche);
                getchar();

                if (coiche !=0)
                {
                    friendlist[friendcount] = resultindex[coiche-1];
                    friendcount++;
                }
                
            }
        }

        if (input == 2)
        {
            int coiche =0;
            for (int i = 0; i < friendcount; i++)
            {
                int index = friendlist[i];
                printf("%d. | %s | %s | %s\n", (i + 1), userIds[index], names[index], email[index]);
            }
            printf("input the number you want to remove [0 to exit] : ");

            scanf("%d", &coiche); getchar();

            if (coiche !=0)
                {
                    for (int i = coiche-1; i < friendcount-1; i++)
                    {
                        friendlist[i] = friendlist[i+1];
                    }
                    friendcount--;
                    
                }

            
        }

    } while (input != 3);
}