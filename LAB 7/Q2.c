#include <stdio.h>

int main()
{
    int E, F;
    int i, j, x;
    int breakCase, surviveCase, worst;
    int dp[20][200];

    printf("Enter number of eggs: ");
    scanf("%d", &E);

    printf("Enter number of floors: ");
    scanf("%d", &F);

    // Base cases
    for(i=1;i<=E;i++)
    {
        dp[i][0]=0;
        dp[i][1]=1;
    }

    for(j=1;j<=F;j++)
        dp[1][j]=j;

    // Dynamic Programming
    for(i=2;i<=E;i++)
    {
        for(j=2;j<=F;j++)
        {
            dp[i][j]=100000;

            for(x=1;x<=j;x++)
            {
                breakCase=dp[i-1][x-1];
                surviveCase=dp[i][j-x];

                if(breakCase>surviveCase)
                    worst=breakCase;
                else
                    worst=surviveCase;

                if(worst+1<dp[i][j])
                    dp[i][j]=worst+1;
            }
        }
    }

    printf("\nMinimum guaranteed drops = %d\n", dp[E][F]);

    return 0;
}