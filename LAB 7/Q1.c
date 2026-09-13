#include <stdio.h>

int main()
{
    int n, i, j;
    int totalCoins, minMoves;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    totalCoins = n * (n + 1) / 2;
    minMoves = (n * (n + 1)) / 6;

    printf("\nOriginal Coin Triangle:\n");

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i;j++)
            printf(" ");

        for(j=1;j<=i;j++)
            printf("O ");

        printf("\n");
    }

    printf("\nInverted Coin Triangle:\n");

    for(i=n;i>=1;i--)
    {
        for(j=1;j<=n-i;j++)
            printf(" ");

        for(j=1;j<=i;j++)
            printf("O ");

        printf("\n");
    }

    printf("\nTotal Coins = %d\n", totalCoins);
    printf("Minimum Moves Required = %d\n", minMoves);

    return 0;
}