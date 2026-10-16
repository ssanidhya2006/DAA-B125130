#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n, i, j;
    int start[MAX], end[MAX];
    int rooms = 0, maxRooms = 0;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of meetings.\n");
        return 0;
    }

    printf("Enter start and end times of each meeting:\n");

    for (i = 0; i < n; i++) {
        scanf("%d %d", &start[i], &end[i]);

        if (start[i] < 0 || end[i] > 24 ||
            start[i] >= end[i]) {
            printf("Invalid meeting time.\n");
            return 0;
        }
    }

    // Sort start times and end times separately
    qsort(start, n, sizeof(int), compare);
    qsort(end, n, sizeof(int), compare);

    i = 0;
    j = 0;

    // Process meetings in start-time order
    while (i < n) {
        if (start[i] < end[j]) {
            // A new room is needed
            rooms++;

            if (rooms > maxRooms)
                maxRooms = rooms;

            i++;
        } else {
            // A room has become free
            rooms--;
            j++;
        }
    }

    printf("Minimum number of meeting rooms = %d\n", maxRooms);

    return 0;
}