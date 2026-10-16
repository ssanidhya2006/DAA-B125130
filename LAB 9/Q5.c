#include <stdio.h>

#define MAX 1000

int main() {
    int n, i;
    int rating[MAX], candy[MAX];
    long long total = 0;

    printf("Enter number of children: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of children.\n");
        return 0;
    }

    printf("Enter the ratings of the children:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &rating[i]);
        candy[i] = 1;
    }

    // First pass: left to right
    for (i = 1; i < n; i++) {
        if (rating[i] > rating[i - 1]) {
            candy[i] = candy[i - 1] + 1;
        }
    }

    // Second pass: right to left
    for (i = n - 2; i >= 0; i--) {
        if (rating[i] > rating[i + 1] &&
            candy[i] <= candy[i + 1]) {
            candy[i] = candy[i + 1] + 1;
        }
    }

    // Calculate total candies
    for (i = 0; i < n; i++) {
        total += candy[i];
    }

    printf("\nChild ratings: ");
    for (i = 0; i < n; i++) {
        printf("%d ", rating[i]);
    }

    printf("\nCandies given: ");
    for (i = 0; i < n; i++) {
        printf("%d ", candy[i]);
    }

    printf("\nMinimum total candies = %lld\n", total);

    return 0;
}