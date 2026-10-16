#include <stdio.h>

struct Station {
    int distance;
    int fuel;
    int used;
};

int main() {
    int n, D, F;
    int i, best, stops = 0;
    long long reach;

    printf("Enter destination distance: ");
    scanf("%d", &D);

    printf("Enter initial fuel: ");
    scanf("%d", &F);

    printf("Enter number of fuel stations: ");
    scanf("%d", &n);

    struct Station s[n];

    for (i = 0; i < n; i++) {
        printf("Enter distance and fuel of station %d: ", i + 1);
        scanf("%d %d", &s[i].distance, &s[i].fuel);
        s[i].used = 0;
    }

    reach = F;

    while (reach < D) {
        best = -1;

        // Find the reachable unused station with maximum fuel
        for (i = 0; i < n; i++) {
            if (s[i].used == 0 && s[i].distance <= reach) {
                if (best == -1 || s[i].fuel > s[best].fuel) {
                    best = i;
                }
            }
        }

        // No reachable station is available
        if (best == -1) {
            printf("Destination cannot be reached.\n");
            return 0;
        }

        // Refuel at the selected station
        reach += s[best].fuel;
        s[best].used = 1;
        stops++;

        printf("Refuel at distance %d, fuel added = %d\n",
               s[best].distance, s[best].fuel);
    }

    printf("Minimum number of stops = %d\n", stops);

    return 0;
}