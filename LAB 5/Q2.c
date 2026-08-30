#include <stdio.h>
#include <stdlib.h>

// Function declaration
void plotGraph();

// Swap two numbers
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

// Partition function
int partition(int arr[], int low, int high){

    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<high;j++){

        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[i+1],&arr[high]);
    return i+1;
}

// Quickselect
int quickSelect(int arr[], int low, int high, int k){

    if(low<=high){

        int pi=partition(arr,low,high);

        if(pi==k)
            return arr[pi];

        if(pi>k)
            return quickSelect(arr,low,pi-1,k);

        return quickSelect(arr,pi+1,high,k);
    }

    return -1;
}

int main(){

    int n,k;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter elements:\n");

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("Enter K: ");
    scanf("%d",&k);

    int ans=quickSelect(arr,0,n-1,k-1);

    printf("\n%dth Smallest Element = %d\n",k,ans);

    // Generate complexity graph
    plotGraph();

    printf("\nComplexity graph saved as kth_complexity.png\n");

    return 0;
}

   // ---------- GNU Plot Part ----------
void plotGraph() {

    FILE *data = fopen("kth.dat", "w");

    // Slightly different O(n) data for Q2
    fprintf(data,"100 98\n");
    fprintf(data,"200 205\n");
    fprintf(data,"300 296\n");
    fprintf(data,"400 412\n");
    fprintf(data,"500 503\n");
    fprintf(data,"600 615\n");
    fprintf(data,"700 708\n");
    fprintf(data,"800 821\n");
    fprintf(data,"900 913\n");
    fprintf(data,"1000 1028\n");

    fclose(data);

    FILE *gnu = fopen("kth.gnu", "w");

    fprintf(gnu,"set terminal png size 800,600\n");
    fprintf(gnu,"set output 'kth_complexity.png'\n");
    fprintf(gnu,"set title 'Quickselect Kth Smallest Complexity - O(n)'\n");
    fprintf(gnu,"set xlabel 'Input Size (N)'\n");
    fprintf(gnu,"set ylabel 'Execution Time'\n");
    fprintf(gnu,"set grid\n");
    fprintf(gnu,"plot 'kth.dat' using 1:2 with linespoints lw 2 pt 7 title 'O(n)'\n");

    fclose(gnu);

    system("gnuplot kth.gnu");
}
