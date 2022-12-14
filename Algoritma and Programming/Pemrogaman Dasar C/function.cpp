#include <stdio.h>
void Calculate(int X, int Y, int *P, int *Q)
{
    *P = X + Y;
    *Q = X * Y;
}

int main()
{
    int X, Y, P, Q; /*local variable*/
    printf("X =");
    scanf("%d", &X);
    printf("Y =");
    scanf("%d", &Y);
    // menggunakan alamat & karena variabel P dan Q tidak memiliki nilai dari main, dan akan menjadi wadah dari hasil di function
    Calculate(X, Y, &P, &Q);
    printf("X + Y = %d\n", P);
    printf("X * Y = %d\n", Q);
}
