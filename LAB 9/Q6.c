#include <stdio.h>
#include <string.h>

#define MAX 1000
#define CHARSET 256

int main() {
    char s[MAX], result[MAX];
    int freq[CHARSET] = {0};
    int lastPos[CHARSET];
    int n, k, i, c, best;
    int possible = 1;

    printf("Enter the string: ");
    scanf("%999s", s);

    printf("Enter the value of K: ");
    scanf("%d", &k);

    if (k < 1) {
        printf("K must be at least 1.\n");
        return 0;
    }

    n = strlen(s);

    // Count character frequencies
    for (i = 0; i < n; i++) {
        freq[(unsigned char)s[i]]++;
    }

    // Initially, no character has been used
    for (i = 0; i < CHARSET; i++) {
        lastPos[i] = -1000000;
    }

    // Build the rearranged string
    for (i = 0; i < n; i++) {
        best = -1;

        // Find the available character with highest frequency
        for (c = 0; c < CHARSET; c++) {
            if (freq[c] > 0 && i - lastPos[c] >= k) {
                if (best == -1 || freq[c] > freq[best]) {
                    best = c;
                }
            }
        }

        // No character can be placed here
        if (best == -1) {
            possible = 0;
            break;
        }

        result[i] = (char)best;
        freq[best]--;
        lastPos[best] = i;
    }

    result[n] = '\0';

    if (possible) {
        printf("Reorganised string: %s\n", result);
    } else {
        printf("Reorganisation is impossible.\n");
        printf("Result: empty string\n");
    }

    return 0;
}