#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Song
{
    char songName[100];
    char songArtis[100];
    int songDuration;
};

struct Playlist
{
    char name[100];
    Song songs[100];
    int songCount;
} playlists[100];

int playlistCount = 0;

int cekPlaylist(char songPlaylist[])
{
    // binary search
    int left = 0;
    int right = playlistCount - 1;
    int mid = 0;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (strcmpi(playlists[mid].name, songPlaylist) == 0)
        {
            return mid;
        }
        if (strcmpi(songPlaylist, playlists[mid].name) < 0)
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

void importSong()
{
    // open file
    FILE *song;
    song = fopen("songs.txt", "r");

    // variabel untuk membaca file
    char songName[100];
    char songArtis[100];
    int songDuration;
    char songPlaylist[100];

    // membaca file sampai akhir
    while (!feof(song))
    {
        fscanf(song, "%[^#]#%[^#]#%d#%[^\n]\n", songName, songArtis, &songDuration, songPlaylist);

        // variabel untuk playlist baru
        Playlist newPlaylist;

        // untuk mengecek apakah playlistnya sudah exist apa belum
        int searchIndex = cekPlaylist(songPlaylist);

        if (searchIndex != -1)
        {
            // playlist sudah exist
            newPlaylist = playlists[searchIndex];
        }
        else
        {
            // belum exist maka buat baru palylistnya, dan set songcount 0
            strcpy(newPlaylist.name, songPlaylist);
            newPlaylist.songCount = 0;
        }

        // memasukkan song kedalam stuct plallist
        Song newSong;
        strcpy(newSong.songName, songName);
        strcpy(newSong.songArtis, songArtis);
        newSong.songDuration = songDuration;

        newPlaylist.songs[newPlaylist.songCount] = newSong;
        newPlaylist.songCount++;

        if (searchIndex == -1)
        {
            // kalau playlistnya belum ada maka buat baru dan countnya++
            playlists[playlistCount] = newPlaylist;
            playlistCount++;
        }
        else
        {
            // kalau palylist sudah ada
            playlists[searchIndex] = newPlaylist;
        }
    }
    fclose(song);
}

void swapSong(Song arrSong[], int i, int j)
{
    Song temp;
    temp = arrSong[i];
    arrSong[i] = arrSong[j];
    arrSong[j] = temp;
}

int partition(Song arrSong[], int left, int right)
{
    Song pivot = arrSong[right];
    int j = left;
    int i = left - 1;

    while (j < right)
    {
        if (strcmpi(arrSong[j].songName, pivot.songName) < 0)
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
    if (left < right)
    {
        int pos = partition(arrSong, left, right);
        quickSortSong(arrSong, left, pos - 1);
        quickSortSong(arrSong, pos + 1, right);
    }
}
void swapPlaylist(Playlist playlists[], int i, int j)
{
    Playlist temp;
    //	strcpy(temp.name, playlists[i].name);
    temp = playlists[i];
    playlists[i] = playlists[j];
    playlists[j] = temp;
}

int partitionPlaylist(Playlist playlists[], int left, int right)
{
    Playlist pivot = playlists[right];

    int i = left - 1;
    int j = left;

    while (j < right)
    {
        if (strcmpi(playlists[j].name, pivot.name) < 0)
        {
            i++;
            swapPlaylist(playlists, i, j);
        }
        j++;
    }
    swapPlaylist(playlists, i + 1, right);
    return (i + 1);
}

void quickSortPlaylist(Playlist playlists[], int left, int right)
{
    if (left < right)
    {
        int pos = partitionPlaylist(playlists, left, right);
        quickSortPlaylist(playlists, left, pos - 1);
        quickSortPlaylist(playlists, pos + 1, right);
    }
}

void insertSong()
{
    char songName[100] = {};
    char songArtis[100] = {};
    int songDuration = 0;
    char songPlaylist[100] = {};

    do
    {
        printf("Song Name[must not be empty]: ");
        scanf("%[^\n]", songName);
        getchar();
    } while (strlen(songName) <= 0);

    do
    {
        printf("Song Artist[must not be empty]: ");
        scanf("%[^\n]", songArtis);
        getchar();
    } while (strlen(songArtis) <= 0);

    do
    {
        printf("Song Duration(ins seconds) [must be more than 0]: ");
        scanf("%d", &songDuration);
        getchar();
    } while (songDuration <= 0);

    do
    {
        printf("Playlist Name [must not be empty]: ");
        scanf("%[^\n]", songPlaylist);
        getchar();
    } while (strlen(songPlaylist) <= 0);

    // cek apakah playlistnya sudah ada apa belum
    Playlist newPlaylist;
    int searchIndex = cekPlaylist(songPlaylist);

    if (searchIndex != -1)
    {
        newPlaylist = playlists[searchIndex];
    }
    else
    {
        strcpy(newPlaylist.name, songPlaylist);
        newPlaylist.songCount = 0;
    }

    // memasukkan lagu
    Song newSong;
    strcpy(newSong.songName, songName);
    strcpy(newSong.songArtis, songArtis);
    newSong.songDuration = songDuration;

    newPlaylist.songs[newPlaylist.songCount] = newSong;
    newPlaylist.songCount++;

    // setelah lagu berhasil dimasukkan maka selanjutnya dilakukan sorting denga quick
    quickSortSong(newPlaylist.songs, 0, newPlaylist.songCount - 1);

    // cek apakah lagu dalam playlist yang sudah exist atau dari playlist baru
    if (searchIndex == -1)
    {
        playlists[playlistCount] = newPlaylist;
        playlistCount++;
    }
    else
    {
        playlists[searchIndex] = newPlaylist;
    }

    // setelah diketahui playlist dari lagu baru, lakukan sorting playlist
    quickSortPlaylist(playlists, 0, playlistCount - 1);
}

void viewAll()
{
    for (int i = 0; i < playlistCount; i++)
    {
        printf("Playlist: %s\n", playlists[i].name);
        for (int j = 0; j < playlists[i].songCount; j++)
        {
            printf("    | %s | %s | %d |\n", playlists[i].songs[j].songName, playlists[i].songs[j].songArtis, playlists[i].songs[j].songDuration);
        }
    }
}

void searchSong()
{
    char search[100];

    do
    {

        printf("Song to search [must be not empty]:");
        scanf("%[^\n]", search);
        getchar();

    } while (strlen(search) <= 0);

    for (int i = 0; i < playlistCount; i++)
    {
        for (int j = 0; j < playlists[i].songCount; j++)
        {
            if (strstr(playlists[i].songs[j].songName, search))
            {
                printf("Playlist : %s\n", playlists[i].name);
                printf("    | %s | %s | %d |\n", playlists[i].songs[j].songName, playlists[i].songs[j].songArtis, playlists[i].songs[j].songDuration);
            }
        }
    }
}

void exit()
{
    FILE *song;
    song = fopen("songs.txt", "w");

    for (int i = 0; i < playlistCount; i++)
    {
        for (int j = 0; j < playlists[i].songCount; j++)
        {
            fprintf(song, "%s#%s#%d#%s\n", playlists[i].songs[j].songName, playlists[i].songs[j].songArtis, playlists[i].songs[j].songDuration, playlists[i].name);
        }
    }
    fclose(song);
}

int main()
{
    importSong();
    int input;
    do
    {
        puts("Song Player");
        puts("==============");
        puts("1. Add new song");
        puts("2. Show all song");
        puts("3. Search song");
        puts("4. Exit");
        printf("Choose>> ");
        scanf("%d", &input);
        getchar();
        switch (input)
        {
        case 1:
            system("cls");
            insertSong();
            system("cls");
            break;

        case 2:
            system("cls");
            viewAll();
            break;

        case 3:
            system("cls");
            searchSong();
            break;
        }

    } while (input != 4);

    exit();
}
