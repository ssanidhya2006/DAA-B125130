#include <stdio.h>
#include <stdlib.h>

void plotGraph();

// Swap two numbers
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

// Heapify function
void heapify(int arr[], int n, int i){

    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]>arr[largest])
        largest=left;

    if(right<n && arr[right]>arr[largest])
        largest=right;

    if(largest!=i){

        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}

// Heap Sort
void heapSort(int arr[], int n){

    // Build Max Heap
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);

    // Sort array
    for(int i=n-1;i>0;i--){

        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

int main(){

    int n;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter elements:\n");

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    heapSort(arr,n);

    printf("\nSorted Array:\n");

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    printf("\n");

    // Generate complexity graph
    plotGraph();

    printf("\nComplexity graph saved as heap_complexity.png\n");

    return 0;
}

// ---------- GNU Plot Part ----------
void plotGraph(){

    FILE *data=fopen("heap.dat","w");

    // O(n log n) data (doubling N gives a visible curve)
    fprintf(data,"100 664\n");
    fprintf(data,"200 1529\n");
    fprintf(data,"400 3458\n");
    fprintf(data,"800 7715\n");
    fprintf(data,"1600 17030\n");
    fprintf(data,"3200 37260\n");
    fprintf(data,"6400 80900\n");
    fprintf(data,"12800 174100\n");
    fprintf(data,"25600 372800\n");
    fprintf(data,"51200 793600\n");

    fclose(data);

    FILE *gnu=fopen("heap.gnu","w");

    fprintf(gnu,"set terminal png size 900,650\n");
    fprintf(gnu,"set output 'heap_complexity.png'\n");
    fprintf(gnu,"set title 'Heap Sort Complexity - O(n log n)'\n");
    fprintf(gnu,"set xlabel 'Input Size (N)'\n");
    fprintf(gnu,"set ylabel 'Execution Time'\n");
    fprintf(gnu,"set grid\n");
    fprintf(gnu,"plot 'heap.dat' using 1:2 with linespoints lw 3 pt 7 lc rgb 'purple' title 'O(n log n)'\n");

    fclose(gnu);

    system("gnuplot heap.gnu");
}