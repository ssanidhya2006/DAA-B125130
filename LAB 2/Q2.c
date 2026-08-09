#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 5000

int arr[MAX];
int arrCopy[MAX];
int temp[MAX];

long mergeComparisons=0;
long modifiedComparisons=0;

void resetCounters()
{
    mergeComparisons=0;
    modifiedComparisons=0;
}

void generateArray(int a[],int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        a[i]=rand()%1000;
    }
}

void copyArray(int source[],int destination[],int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        destination[i]=source[i];
    }
}

void printArray(int a[],int n)
{
    int i;

    if(n>20)
        n=20;

    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    printf("\n");
}

void printHeading()
{
    printf("\n");
    printf("====================================================\n");
    printf("MERGE SORT VS MODIFIED THREE WAY MERGE SORT\n");
    printf("====================================================\n");
}

void merge(int a[],int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=low;

    while(i<=mid && j<=high)
    {
        mergeComparisons++;

        if(a[i]<=a[j])
        {
            temp[k]=a[i];
            i++;
        }
        else
        {
            temp[k]=a[j];
            j++;
        }

        k++;
    }

    while(i<=mid)
    {
        temp[k]=a[i];
        i++;
        k++;
    }

    while(j<=high)
    {
        temp[k]=a[j];
        j++;
        k++;
    }

    for(i=low;i<=high;i++)
    {
        a[i]=temp[i];
    }
}

void mergeSort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;

        mergeSort(a,low,mid);

        mergeSort(a,mid+1,high);

        merge(a,low,mid,high);
    }
}

void testMergeSort(int n)
{
    copyArray(arr,arrCopy,n);

    mergeComparisons=0;

    mergeSort(arrCopy,0,n-1);

    printf("\n");
    printf("=========================================\n");
    printf("MERGE SORT\n");
    printf("=========================================\n");

    printf("Original Array (First 20 Elements)\n");
    printArray(arr,n);

    printf("\n");

    printf("Sorted Array (First 20 Elements)\n");
    printArray(arrCopy,n);

    printf("\n");

    printf("Comparisons : %ld\n",mergeComparisons);

    printf("=========================================\n");
}

void mergeThree(int a[], int low, int mid1, int mid2, int high)
{
    int i = low;
    int j = mid1 + 1;
    int k = mid2 + 1;
    int t = low;

    while(i <= mid1 && j <= mid2 && k <= high)
    {
        modifiedComparisons++;

        if(a[i] <= a[j] && a[i] <= a[k])
            temp[t++] = a[i++];
        else if(a[j] <= a[i] && a[j] <= a[k])
            temp[t++] = a[j++];
        else
            temp[t++] = a[k++];
    }

    while(i <= mid1 && j <= mid2)
    {
        modifiedComparisons++;

        if(a[i] <= a[j])
            temp[t++] = a[i++];
        else
            temp[t++] = a[j++];
    }

    while(j <= mid2 && k <= high)
    {
        modifiedComparisons++;

        if(a[j] <= a[k])
            temp[t++] = a[j++];
        else
            temp[t++] = a[k++];
    }

    while(i <= mid1 && k <= high)
    {
        modifiedComparisons++;

        if(a[i] <= a[k])
            temp[t++] = a[i++];
        else
            temp[t++] = a[k++];
    }

    while(i <= mid1)
        temp[t++] = a[i++];

    while(j <= mid2)
        temp[t++] = a[j++];

    while(k <= high)
        temp[t++] = a[k++];

    for(i = low; i <= high; i++)
        a[i] = temp[i];
}

void modifiedMergeSort(int a[], int low, int high)
{
    if(low >= high)
        return;

    int third = (high - low + 1) / 3;

    if(third == 0)
        third = 1;

    int mid1 = low + third - 1;
    int mid2 = mid1 + third;

    if(mid1 >= high)
        mid1 = low;

    if(mid2 >= high)
        mid2 = high - 1;

    modifiedMergeSort(a, low, mid1);
    modifiedMergeSort(a, mid1 + 1, mid2);
    modifiedMergeSort(a, mid2 + 1, high);

    mergeThree(a, low, mid1, mid2, high);
}

void testModifiedMergeSort(int n)
{
    copyArray(arr, arrCopy, n);

    modifiedComparisons = 0;

    modifiedMergeSort(arrCopy, 0, n - 1);

    printf("\n");
    printf("=========================================\n");
    printf("MODIFIED THREE WAY MERGE SORT\n");
    printf("=========================================\n");

    printf("Original Array (First 20 Elements)\n");
    printArray(arr, n);

    printf("\n");

    printf("Sorted Array (First 20 Elements)\n");
    printArray(arrCopy, n);

    printf("\n");

    printf("Comparisons : %ld\n", modifiedComparisons);

    printf("=========================================\n");
}

void generateReport()
{
    FILE *fp;

    int n;

    fp = fopen("merge.txt","w");

    if(fp == NULL)
    {
        printf("Unable to create merge.txt\n");
        return;
    }

    fprintf(fp,"Input MergeSort ModifiedMergeSort\n");

    for(n=100;n<=1000;n+=100)
    {
        printf("\n");
        printf("====================================================\n");
        printf("INPUT SIZE : %d\n",n);
        printf("====================================================\n");

        generateArray(arr,n);

        printf("\nOriginal Array (First 20 Elements)\n");
        printArray(arr,n);

        resetCounters();

        copyArray(arr,arrCopy,n);

        mergeSort(arrCopy,0,n-1);

        long mergeValue=mergeComparisons;

        printf("\nSorted Array using Merge Sort (First 20 Elements)\n");
        printArray(arrCopy,n);

        printf("\nMerge Sort Comparisons : %ld\n",mergeValue);

        copyArray(arr,arrCopy,n);

        modifiedComparisons=0;

        modifiedMergeSort(arrCopy,0,n-1);

        long modifiedValue=modifiedComparisons;

        printf("\nSorted Array using Modified Merge Sort (First 20 Elements)\n");
        printArray(arrCopy,n);

        printf("\nModified Merge Sort Comparisons : %ld\n",modifiedValue);

        fprintf(fp,"%d %ld %ld\n",
                n,
                mergeValue,
                modifiedValue);

        printf("\n----------------------------------------------------\n");
    }

    fclose(fp);

    printf("\n");
    printf("====================================================\n");
    printf("merge.txt Generated Successfully.\n");
    printf("====================================================\n");
}

void showFile()
{
    FILE *fp;

    char ch;

    fp=fopen("merge.txt","r");

    if(fp==NULL)
    {
        printf("Unable to Open merge.txt\n");
        return;
    }

    printf("\n");
    printf("====================================================\n");
    printf("Contents of merge.txt\n");
    printf("====================================================\n\n");
}

void plotGraph()
{
    FILE *gp;

    gp = popen("gnuplot -persistent","w");

    if(gp==NULL)
    {
        printf("\nUnable to Open GNUplot.\n");
        return;
    }

    fprintf(gp,"set terminal pngcairo size 1000,700\n");
    fprintf(gp,"set output 'merge_graph.png'\n");

    fprintf(gp,"set title 'Merge Sort vs Modified Three Way Merge Sort'\n");
    fprintf(gp,"set xlabel 'Input Size'\n");
    fprintf(gp,"set ylabel 'Number of Comparisons'\n");

    fprintf(gp,"set grid\n");
    fprintf(gp,"set key outside\n");

    fprintf(gp,"set style line 1 lw 3\n");
    fprintf(gp,"set style line 2 lw 3\n");

    fprintf(gp,
    "plot 'merge.txt' using 1:2 with linespoints ls 1 title 'Merge Sort',"
    "'merge.txt' using 1:3 with linespoints ls 2 title 'Modified Three Way Merge Sort'\n");

    fprintf(gp,"set terminal wxt\n");
    fprintf(gp,"unset output\n");

    fprintf(gp,
    "plot 'merge.txt' using 1:2 with linespoints ls 1 title 'Merge Sort',"
    "'merge.txt' using 1:3 with linespoints ls 2 title 'Modified Three Way Merge Sort'\n");

    fflush(gp);

    pclose(gp);

    printf("\n");
    printf("====================================================\n");
    printf("Graph Generated Successfully.\n");
    printf("Data File  : merge.txt\n");
    printf("Graph File : merge_graph.png\n");
    printf("GNUplot Executed Successfully.\n");
    printf("====================================================\n");
}

int main()
{
    int choice;

    srand(time(NULL));

    printHeading();

    printf("\n");
    printf("Press 1 to Start the Analysis : ");
    scanf("%d",&choice);

    if(choice!=1)
    {
        printf("\nProgram Terminated.\n");
        return 0;
    }

    printf("\n");
    printf("Generating Random Arrays...\n");
    printf("Please Wait...\n");

    generateReport();

    printf("\n");
    printf("Displaying merge.txt...\n");

    showFile();

    printf("\n");
    printf("Generating Graph...\n");

    plotGraph();

    printf("\n");
    printf("====================================================\n");
    printf("SUMMARY\n");
    printf("====================================================\n");
    printf("Merge Sort Executed Successfully.\n");
    printf("Modified Three Way Merge Sort Executed Successfully.\n");
    printf("Comparison Analysis Completed.\n");
    printf("merge.txt Generated Successfully.\n");
    printf("merge_graph.png Generated Successfully.\n");
    printf("GNUplot Executed Successfully.\n");
    printf("====================================================\n");

    printf("\n");
    printf("THANK YOU\n");

    return 0;
}