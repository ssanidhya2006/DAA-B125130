#include <stdio.h>
#include <stdlib.h>

// Function declaration
void plotGraph();

// Swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quickselect function
int quickSelect(int arr[], int low, int high, int k) {

    if (low <= high) {

        int pi = partition(arr, low, high);

        if (pi == k)
            return arr[pi];

        if (pi > k)
            return quickSelect(arr, low, pi - 1, k);

        return quickSelect(arr, pi + 1, high, k);
    }

    return -1;
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int median = quickSelect(arr, 0, n - 1, n / 2);

    printf("\nMedian = %d\n", median);

    // Generate GNU Plot graph
    plotGraph();

    printf("\nComplexity graph saved as median_complexity.png\n");

    return 0;
}

// ---------- GNU Plot Part ----------
void plotGraph() {

    FILE *data = fopen("median.dat", "w");

    // O(n) data points
    for (int i = 100; i <= 1000; i += 100)
        fprintf(data, "%d %d\n", i, i);

    fclose(data);

    FILE *gnu = fopen("median.gnu", "w");

    fprintf(gnu, "set terminal png size 800,600\n");
    fprintf(gnu, "set output 'median_complexity.png'\n");
    fprintf(gnu, "set title 'Quickselect Median Complexity - O(n)'\n");
    fprintf(gnu, "set xlabel 'Input Size (N)'\n");
    fprintf(gnu, "set ylabel 'Time Complexity'\n");
    fprintf(gnu, "set grid\n");
    fprintf(gnu, "plot 'median.dat' using 1:2 with linespoints lw 2 pt 7 title 'O(n)'\n");

    fclose(gnu);

    // Run GNU Plot automatically
    system("gnuplot median.gnu");
}