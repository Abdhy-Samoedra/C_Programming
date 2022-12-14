#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Song
{
    char name[100];
    char artist[100];
    int duration;
};

struct Playlist
{
    char name[100];
    Song songs[100];
    int songCount;
} playlists[100];

int playlistCount = 0;

int lookupExistingPlaylist(char lookupPlaylist[])
{
    // binary search
    // requairement = left, right, mid

    int left = 0;
    int right = playlistCount - 1;
    int mid = 0;

    // cari data sampai left > right
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (strcmpi(playlists[mid].name, lookupPlaylist) == 0)
        {
            return mid;
        }

        // perkecil scope pemncarian, gerak kiri jika hsil pncarisn < mid, kanan jika hail pnacarian > mid
        if (strcmpi(lookupPlaylist, playlists[mid].name) < 0)
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
void importSongData()
{
    FILE *fd = fopen("songs.txt", "r");

    while (!feof(fd))
    {
        char songname[100];
        char songartist[100];
        int songduration;
        char playlistname[100];
        fscanf(fd, "%[^#]#%[^#]#%d#%[^\n]\n", songname, songartist, &songduration, playlistname);

        // cek apakah sudah ada playlist yang dibaca
        Playlist newPlaylist;
        int searchIndex = lookupExistingPlaylist(playlistname);
        if (searchIndex != -1)
        {
            // ambil playlisyt yang ada
            newPlaylist = playlists[searchIndex];
        }
        else
        {
            // masukan data ke dalam variable dari struct yang teklah dibuat
            // memasukkan data playlist dulu
            strcpy(newPlaylist.name, playlistname);
            newPlaylist.songCount = 0;
        }

        // memasukkan data song kedalam playlist
        Song newSong;
        strcpy(newSong.name, songname);
        strcpy(newSong.artist, songartist);
        newSong.duration = songduration;

        newPlaylist.songs[newPlaylist.songCount] = newSong;
        newPlaylist.songCount++;

        // masukkan playlist baru kedalam data playlist  yang ada
        if (searchIndex == -1)
        {
            playlists[playlistCount] = newPlaylist;
            playlistCount++;
        }
        else
        {
            playlists[searchIndex] = newPlaylist;
        }
    }
    
}
void swapPlaylist(int l, int r)
{

    Playlist temp;
    temp = playlists[l];
    playlists[l] = playlists[r];
    playlists[r] = temp;
}

int partitions(Playlist list[], int left, int right)
{
    Playlist pivot_playlist = list[right];

    int i = left - 1;
    int j = left;
    while (j < right)
    {
        if (strcmpi(playlists[j].name, pivot_playlist.name) < 0)
        {
            i++;
            swapPlaylist(i, j);
        }
        j++;
    }
    swapPlaylist(i + 1, j);
    return (i + 1);
}
void quickSortPlaylist(int l, int r)
{

    if (l < r)
    {
        int part = partitions(playlists, l, r);
        quickSortPlaylist(l, part - 1);
        quickSortPlaylist(part + 1, r);
    }
}

void swapSong(Song arrSong[], int a, int b)
{
    Song temp;
    strcpy(temp.name, arrSong[a].name);
    strcpy(temp.artist, arrSong[a].artist);
    temp.duration = arrSong[a].duration;

    arrSong[a] = arrSong[b];
    arrSong[b] = temp;
}

int partition(Song arrSong[], int left, int right)
{
    Song pivotSong = arrSong[right];

    int j = left;
    int i = left - 1;

    while (j < right)
    {
        if (strcmpi(arrSong[j].name, pivotSong.name) < 0)
        {
            i++;
            swapSong(arrSong, i, j);
        }
        j++;
    }
    swapSong(arrSong, i + 1, right);
    return (i + 1);
}

void quickSortSong(Song arrSong[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int pos = partition(arrSong, left, right);
    quickSortSong(arrSong, left, pos - 1);
    quickSortSong(arrSong, pos + 1, right);
}

void insertMenu()
{
    char songName[255] = {}, songArtist[255] = {}, playlistName[255] = {};
    int songDuration = 0;

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

    Playlist newPlaylist;
    // cek dan cari apakh playlistnya sudah ada apa belum
    int searchIndex = lookupExistingPlaylist(playlistName);

    if (searchIndex != -1)
    {
        // kalau ketemu
        newPlaylist = playlists[searchIndex];
    }
    else
    {
        // kalau tidak ketemu / playlistnya masih baru
        strcpy(newPlaylist.name, playlistName);
        newPlaylist.songCount = 0;
    }

    Song newSong;
    strcpy(newSong.name, songName);
    strcpy(newSong.artist, songArtist);
    newSong.duration = songDuration;

    newPlaylist.songs[newPlaylist.songCount] = newSong;
    newPlaylist.songCount++;

    quickSortSong(newPlaylist.songs, 0, newPlaylist.songCount - 1);

    if (searchIndex == -1)
    {
        // kalau dia playlist baru, maka dimasukkan array
        playlists[playlistCount] = newPlaylist;
        playlistCount++;
    }
    else
    {
        playlists[searchIndex] = newPlaylist;
    }
    quickSortPlaylist(0, playlistCount - 1);
}

void viewAll()
{
    // looping untuk print playlist
    for (int i = 0; i < playlistCount; i++)
    {
        printf("Playlist: %s\n", playlists[i].name);

        // print song yang ada pada playlistnya
        for (int j = 0; j < playlists[i].songCount; j++)
        {
            printf("    | %s | %s | %d |\n", playlists[i].songs[j].name, playlists[i].songs[j].artist, playlists[i].songs[j].duration);
        }
    }
}

int main()
{
    importSongData();
    int input;
    system("cls");
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
            system("cls");
            insertMenu();
            system("cls");
            break;

        case 2:
            system("cls");
            viewAll();
            break;

            // case 3:
            // searchPlaylist();
            // break;
        }
    } while (input != 4);

    return 0;
}