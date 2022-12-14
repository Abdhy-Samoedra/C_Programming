#include <stdio.h>


int fibonacci(int x, int y, int ke)
{
    if (ke == 0)
    {
        return x;
    }else if (ke == 1)
    {
        return y;
    }else
    {
        return fibonacci(x,y,ke-1) + fibonacci(x,y,ke-2);
    }
    
    
       
}

int main()
{
    // int angka1, angka2, urutan, temp;

    // scanf("%d %d %d", &angka1, &angka2, &urutan);

    // for (int i = 1; i < urutan; i++)
    // {
    //     temp = angka1 + angka2;
    //     angka1 = angka2;
    //     angka2 = temp;
    // }
    // printf("%d\n", angka2);

    int x,y;
    int ke;
    scanf("%d %d",&x,&y);
    scanf("%d",&ke);
    printf("%d\n",fibonacci(x,y,ke));


}