#include <stdio.h>
#include <string.h>

int main()
{
    int kasus,count;
    char kata[100001];
    int cek[2000];
    scanf("%d",&kasus);

    for (int i = 0; i < kasus; i++)
    {
        scanf("%s",kata);
        for (int j = 0; j < strlen(kata); i++)
        {
            if (cek[kata[i] == 0])
            {
                cek[kata[i]] = 1;
                count++;
            }
            
        }
        
    }
    
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char kata[1000001];
//     int vocal = 0;
//     int konsonan = 0;
//     int cek[2000];
//     scanf("%[^\n]", kata);
//     for (int i = 0; i < strlen(kata); i++)
//     {
//         if (kata[i] == 'a' || kata[i] == 'i' || kata[i] == 'u' || kata[i] == 'e' || kata[i] == 'o')
//         {
//             if (cek[kata[i]] == 0)
//             {
//                 cek[kata[i]] = 1;
//                 vocal++;
//             }
//         }
//         else if (kata[i] != 32)
//         {
//             if (cek[kata[i]] == 0)
//             {
//                 konsonan++;
//                 cek[kata[i]] = 1;
//             }
//         }
//     }
//     printf("Vocal: %d\n",vocal);
//     printf("Consonant: %d\n",konsonan);
// }