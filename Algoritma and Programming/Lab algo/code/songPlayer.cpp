#include <stdio.h>
#include <string.h>

struct Song
{
    char songName[100];
    char songArtist[100];
    int duration;
};

struct Playlist
{
    char name[100];
    int songCount;
    Song listsong[20];
};

int playlistCount = 0;
Playlist listPlaylist[20];

int searchPlaylist(char playlistName[])
{
    if (playlistCount == 0)
        return -1;
    int left = 0, right = playlistCount - 1;
    while (left != right)
    {
        int mid = (left + right) / 2;
        if (strcmp(listPlaylist[mid].name, playlistName) == 0)
        {
            return mid;
        }
        else if (strcmp(listPlaylist[mid].name, playlistName) > 0)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

void swapPlaylist(int a, int b)
{
    struct Playlist temp = listPlaylist[a];
    listPlaylist[a] = listPlaylist[b];
    listPlaylist[b] = temp;
}

int partition(char pivot[], int low, int high)
{
    int i = -1;
    int j = low;
    while (j < high)
    {
        if (strcmp(listPlaylist[j].name, pivot) < 0)
        {
            i++;
            swapPlaylist(i, j);
        }
        j++;
    }
    swapPlaylist(high, i + 1);
    return (i + 1);
}

void quickSortPlaylist(int low, int high)
{
    if (low >= high)
    {
        return;
    }

    char pivot[100];
    strcpy(pivot, listPlaylist[high].name);

    int pos = partition(pivot, low, high);
    quickSortPlaylist(low, pos - 1);
    quickSortPlaylist(pos + 1, high);
}

void addMenu()
{
    char songName[255], songArtist[255], playlistName[255];
    int songDuration;

    do
    {
        printf("Input song name [must not be empty]: ");
        scanf("%[^\n]", songName);
        getchar();

    } while (strlen(songName) <= 0);

    do
    {
        printf("Input song Artist [must not be empty]: ");
        scanf("%[^\n]", songArtist);
        getchar();
    } while (strlen(songArtist) <= 0);

    do
    {
        printf("Input song duration (in seconds) [must be more than 1]: ");
        scanf("%d", &songDuration);
        getchar();
    } while (songDuration <= 0);

    do
    {
        printf("Input playlist name [must not be empty]: ");
        scanf("%[^\n]", playlistName);
        getchar();
    } while (strlen(playlistName) <= 0);
    

    if (searchPlaylist(playlistName) == -1)
    {
        strcpy(listPlaylist[playlistCount].name, playlistName);
        playlistCount++;
    }
    quickSortPlaylist(0, playlistCount - 1);
}

void viewAll()
{
    for (int i = 0; i < playlistCount; i++)
    {
        printf("%s Playlist\n", listPlaylist[i].name);
    }
}

int main()
{    

    int input;
    do
    {
        printf("Song Player\n");
        printf("=============\n");
        printf("1. Add new somgs\n");
        printf("2. Show all songs\n");
        printf("3. Search song(s)\n");
        printf("4. Exit\n");
        printf("Choose >> ");
        scanf("%d", &input);
        getchar();
        switch (input)
        {
        case 1:
            addMenu();
            break;

        case 2:
            viewAll();
            break;

            // case 3:
            // searchPlaylist();
            // break;
        }
    } while (input != 4);
}