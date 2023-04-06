#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//      Linear Probing

const int maxArrSize = 20;

struct data
{
    char heroName[20];
    char heroType[20];
    int level;
};

// membuat hash tablenya
struct data *dataArr[maxArrSize];

// membut hash function, contoh ini menggunakan function DIVISION METHOD
int hashFunct(char heroName[]) // parameter nya gunakan variabel paling unique (disini name karena hero dota name gaada yang sama)
{
    // disini first dan last terserah kita, bisa juga menggunakan semua hruf dalam katanya apabila terjadi kesamaan antara huruf awal dan akhir antara kata satu dengn kata lainnnya
    char first = heroName[0];
    char last = heroName[strlen(heroName) - 1];

    int res = (first + last) % maxArrSize;
    return res;
}

void insert(char heroName[], char heroType[], int level)
{
    struct data *temp = (struct data *)malloc(sizeof(struct data));
    strcpy(temp->heroName, heroName);
    strcpy(temp->heroType, heroType);
    temp->level = level;
    // get hash value/key/index from hash function
    int index = hashFunct(heroName);
    printf("%s %d\n",heroName,index);

    // insert to hash table, aply linear probing if needed atau terjadi collusion (dobel)

    // if current index in hash table is empty
    if (dataArr[index] == 0)
    {
        dataArr[index] = temp;
    }
    // if current index in hash table is not empty
    else
    {
        // jika ternyata ada datanya, kita melakukan linear probing
        int currIndex = index;
        while (dataArr[currIndex] != 0) // loop until found empty spot/index
        {
            currIndex++;
            if (currIndex >= maxArrSize)
            {
                currIndex = 0;
            }
            if (currIndex == index)
            {
                break;
            }
        }

        // if array is full
        if (currIndex == index)
        {
            printf("arrayu is full");
        }
        else
        {
            dataArr[currIndex] = temp;
        }
    }
}


void display()
{
    for (int i = 0; i < maxArrSize; i++)
    {
        if (dataArr[i] != 0)
        {
            printf("%s\n", dataArr[i]->heroName);
        }
    }
}

int main()
{
    insert("axe", "str", 1);
    insert("lion", "int", 1); // lion masuk ke axe dan andre karena hasil modulus dari penjumlahan last dam first indenya adalah sama
    insert("invoker", "int", 1);

    display();
    return 0;
}