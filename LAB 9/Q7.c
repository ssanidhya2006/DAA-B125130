#include <stdio.h>

#define MAX 1000

long long heap[MAX];
int size = 0;

// Swap two values
void swap(long long *a, long long *b) {
    long long temp = *a;
    *a = *b;
    *b = temp;
}

// Insert a value into the max-heap
void insert(long long value) {
    int i = size;
    heap[size++] = value;

    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Remove and return the largest value
long long removeMax() {
    long long largest = heap[0];
    heap[0] = heap[--size];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largestIndex = i;

        if (left < size && heap[left] > heap[largestIndex])
            largestIndex = left;

        if (right < size && heap[right] > heap[largestIndex])
            largestIndex = right;

        if (largestIndex == i)
            break;

        swap(&heap[i], &heap[largestIndex]);
        i = largestIndex;
    }

    return largest;
}

int main() {
    int n, i;
    long long x, minValue = 0;
    long long maxValue, deviation, bestDeviation;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid array size.\n");
        return 0;
    }

    printf("Enter positive array elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%lld", &x);

        if (x <= 0 || x > 4000000000000000000LL) {
            printf("Invalid element.\n");
            return 0;
        }

        // Make every element even
        if (x % 2 != 0)
            x *= 2;

        insert(x);

        if (i == 0 || x < minValue)
            minValue = x;
    }

    maxValue = heap[0];
    bestDeviation = maxValue - minValue;

    while (heap[0] % 2 == 0) {
        // Divide the current maximum by 2
        x = removeMax();
        x /= 2;

        // Update the minimum
        if (x < minValue)
            minValue = x;

        insert(x);

        maxValue = heap[0];
        deviation = maxValue - minValue;

        if (deviation < bestDeviation)
            bestDeviation = deviation;

        printf("Current minimum = %lld, maximum = %lld, deviation = %lld\n",
               minValue, maxValue, deviation);
    }

    printf("Minimum deviation = %lld\n", bestDeviation);

    return 0;
}