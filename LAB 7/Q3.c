#include <stdio.h>

int moveCount = 0;

// Function for normal 3-peg Tower of Hanoi
void hanoi3(int n, char from, char aux, char to)
{
    if(n == 0)
        return;

    hanoi3(n-1, from, to, aux);

    printf("Move %2d: Disk %d from %c -> %c\n",
           ++moveCount, n, from, to);

    hanoi3(n-1, aux, from, to);
}

// Function for Reve's Puzzle (4 pegs)
void reve(int n, char A, char B, char C, char D)
{
    if(n == 0)
        return;

    if(n == 1)
    {
        printf("Move %2d: Disk 1 from %c -> %c\n",
               ++moveCount, A, D);
        return;
    }

    int k = n / 2;   // Simple choice (for n=8 gives 33 moves)

    // Step 1: Move top k disks to peg B
    reve(k, A, D, C, B);

    // Step 2: Move remaining disks using 3 pegs
    hanoi3(n-k, A, C, D);

    // Step 3: Move k disks from peg B to peg D
    reve(k, B, A, C, D);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("\nSequence of Moves:\n\n");

    reve(n, 'A', 'B', 'C', 'D');

    printf("\nTotal Moves = %d\n", moveCount);

    return 0;
}