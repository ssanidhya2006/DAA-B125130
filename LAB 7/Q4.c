#include <stdio.h>

int count = 0;

int moves(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;

    return moves(n-1)+2*moves(n-2)+1;
}

void printMoves(int n)
{
    if(n==0) return;
    if(n==1)
    {
        printf("Move %2d: Toggle Switch 1\n", ++count);
        return;
    }
    if(n==2)
    {
        printf("Move %2d: Toggle Switch 2\n", ++count);
        printf("Move %2d: Toggle Switch 1\n", ++count);
        return;
    }

    printMoves(n-2);

    printf("Move %2d: Toggle Switch %d\n", ++count, n);

    printMoves(n-2);

    printMoves(n-1);
}

int main()
{
    int n;

    printf("Enter number of switches: ");
    scanf("%d",&n);

    printf("\nSequence of Moves:\n\n");
    printMoves(n);

    printf("\nTotal Minimum Moves = %d\n", moves(n));

    return 0;
}