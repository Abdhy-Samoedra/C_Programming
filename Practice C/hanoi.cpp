#include <stdio.h>

void towers(int, char, char, char);

int main()
{
    int num;
    printf("Number of disks : ");
    scanf("%d", &num);
    printf("Tower of Hanoi moves:\n");
    towers(num, 'L', 'R', 'M');
    return 0;
}

void towers(int num, char from, char to, char temp)
{
    // Base Condition if no of disks are
    if (num == 1)
    {
        printf("\n Move disk 1 from %c to %c", from, to);
        return;
    }

    // Recursively calling function twice
    towers(num - 1, from, temp, to);
    printf("\n Move disk %d from %c to %c", num, from, to);
    towers(num - 1, temp, to, from);
}