#include <stdio.h>

#define MAX 100

int main() {
    int n, i, a, b, count;
    long long length[2 * MAX];
    int active[2 * MAX] = {0};
    long long cost, totalCost = 0;

    printf("Enter number of sticks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of sticks.\n");
        return 0;
    }

    printf("Enter the lengths of the sticks:\n");

    for (i = 0; i < n; i++) {
        scanf("%lld", &length[i]);

        if (length[i] <= 0) {
            printf("Stick lengths must be positive.\n");
            return 0;
        }

        active[i] = 1;
    }

    count = n;

    while (count > 1) {
        a = -1;
        b = -1;

        // Find the two shortest active sticks
        for (i = 0; i < n + (n - count); i++) {
            if (active[i]) {
                if (a == -1 || length[i] < length[a]) {
                    b = a;
                    a = i;
                } else if (b == -1 || length[i] < length[b]) {
                    b = i;
                }
            }
        }

        // Connect the two shortest sticks
        cost = length[a] + length[b];
        printf("Connect %lld and %lld: cost = %lld\n",
               length[a], length[b], cost);

        totalCost += cost;

        active[a] = 0;
        active[b] = 0;

        // Store the newly formed stick
        length[n + (n - count)] = cost;
        active[n + (n - count)] = 1;

        count--;
    }

    printf("Minimum total cost = %lld\n", totalCost);

    return 0;
}