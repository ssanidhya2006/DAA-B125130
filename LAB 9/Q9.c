#include <stdio.h>

#define MAX 100
#define INF 1000000000000000LL

long long weight[MAX];
long long sum[MAX][MAX];
long long dp[MAX][MAX];
int split[MAX][MAX];

// Print the tree while preserving the order of weights
void printTree(int i, int j)
{
    if (i == j) {
        printf("%d", i + 1);
        return;
    }

    printf("(");
    printTree(i, split[i][j]);
    printf(", ");
    printTree(split[i][j] + 1, j);
    printf(")");
}

int main()
{
    int n, i, j, k, len;
    long long best, cost;

    printf("Enter number of weights: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of weights.\n");
        return 0;
    }

    printf("Enter the weights in order:\n");
    for (i = 0; i < n; i++) {
        scanf("%lld", &weight[i]);

        if (weight[i] <= 0) {
            printf("Weights must be positive.\n");
            return 0;
        }
    }

    // Calculate sums of weights in every interval
    for (i = 0; i < n; i++) {
        sum[i][i] = weight[i];

        for (j = i + 1; j < n; j++) {
            sum[i][j] = sum[i][j - 1] + weight[j];
        }
    }

    // A single weight has depth 0, so its cost is 0
    for (i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    // Find the minimum cost for intervals of increasing length
    for (len = 2; len <= n; len++) {
        for (i = 0; i <= n - len; i++) {
            j = i + len - 1;
            best = INF;

            // Try every possible division into left and right subtrees
            for (k = i; k < j; k++) {
                cost = dp[i][k] + dp[k + 1][j] + sum[i][j];

                if (cost < best) {
                    best = cost;
                    split[i][j] = k;
                }
            }

            dp[i][j] = best;
        }
    }

    printf("\nMinimum weighted depth = %lld\n", dp[0][n - 1]);

    printf("Optimal alphabetic tree: ");
    printTree(0, n - 1);
    printf("\n");

    return 0;
}