#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX 2000

long uaComp = 0;
long saComp = 0;
long slluComp = 0;
long sllsComp = 0;
long dlluComp = 0;
long dllsComp = 0;

int unsortedArray[MAX];
int uaSize = 0;


int sortedArray[MAX];
int saSize = 0;

typedef struct SNode
{
    int data;
    struct SNode *next;
}SNode;

SNode *SUHead = NULL;
SNode *SSHead = NULL;

typedef struct DNode
{
    int data;
    struct DNode *prev;
    struct DNode *next;
}DNode;

DNode *DUHead = NULL;
DNode *DSHead = NULL;


SNode *createSNode(int value)
{
    SNode *temp;

    temp = (SNode *)malloc(sizeof(SNode));

    temp->data = value;
    temp->next = NULL;

    return temp;
}


DNode *createDNode(int value)
{
    DNode *temp;

    temp = (DNode *)malloc(sizeof(DNode));

    temp->data = value;

    temp->prev = NULL;

    temp->next = NULL;

    return temp;
}


void resetCounters()
{
    uaComp = 0;

    saComp = 0;

    slluComp = 0;

    sllsComp = 0;

    dlluComp = 0;

    dllsComp = 0;
}

void printHeading()
{
    printf("\n");

    printf("===============================================\n");

    printf("   DICTIONARY OPERATION ANALYSIS USING C\n");

    printf("===============================================\n");

    printf("Data Structures Used\n");

    printf("1. Unsorted Array\n");

    printf("2. Sorted Array\n");

    printf("3. Singly Linked List (Unsorted)\n");

    printf("4. Singly Linked List (Sorted)\n");

    printf("5. Doubly Linked List (Unsorted)\n");

    printf("6. Doubly Linked List (Sorted)\n");

    printf("===============================================\n");
}

void displayInputSize(int n)
{
    printf("\n");

    printf("-------------------------------------------\n");

    printf("Current Input Size : %d\n", n);

    printf("-------------------------------------------\n");
}

void UA_Insert(int value)
{
    uaComp++;

    unsortedArray[uaSize] = value;

    uaSize++;
}


int UA_Search(int key)
{
    int i;

    for(i=0;i<uaSize;i++)
    {
        uaComp++;

        if(unsortedArray[i]==key)
        {
            return i;
        }
    }

    return -1;
}


void UA_Delete(int key)
{
    int pos;

    pos = UA_Search(key);

    if(pos==-1)
        return;

    int i;

    for(i=pos;i<uaSize-1;i++)
    {
        uaComp++;

        unsortedArray[i]=unsortedArray[i+1];
    }

    uaSize--;
}


int UA_Max()
{
    int i;

    int max=unsortedArray[0];

    for(i=1;i<uaSize;i++)
    {
        uaComp++;

        if(unsortedArray[i]>max)
            max=unsortedArray[i];
    }

    return max;
}


int UA_Min()
{
    int i;

    int min=unsortedArray[0];

    for(i=1;i<uaSize;i++)
    {
        uaComp++;

        if(unsortedArray[i]<min)
            min=unsortedArray[i];
    }

    return min;
}


int UA_Predecessor(int key)
{
    int i;

    int pred=-1;

    for(i=0;i<uaSize;i++)
    {
        uaComp++;

        if(unsortedArray[i]<key)
        {
            if(pred==-1 || unsortedArray[i]>pred)
            {
                pred=unsortedArray[i];
            }
        }
    }

    return pred;
}

int UA_Successor(int key)
{
    int i;

    int succ=-1;

    for(i=0;i<uaSize;i++)
    {
        uaComp++;

        if(unsortedArray[i]>key)
        {
            if(succ==-1 || unsortedArray[i]<succ)
            {
                succ=unsortedArray[i];
            }
        }
    }

    return succ;
}


void UA_Display()
{
    int i;

    printf("\n");

    printf("Unsorted Array : ");

    for(i=0;i<uaSize;i++)
    {
        printf("%d ",unsortedArray[i]);
    }

    printf("\n");
}

/*-------------------------------------------------------
        RUN ALL OPERATIONS
-------------------------------------------------------*/

void UA_Test(int n)
{
    int i;

    uaSize=0;

    for(i=1;i<=n;i++)
    {
        UA_Insert(rand()%1000);
    }

    UA_Search(500);

    UA_Max();

    UA_Min();

    UA_Predecessor(500);

    UA_Successor(500);

    UA_Delete(500);

    printf("\n=====================================\n");

    printf("UNSORTED ARRAY\n");

    printf("=====================================\n");

    printf("Input Size               : %d\n",n);

    printf("Comparisons Performed    : %ld\n",uaComp);

    printf("Maximum Element          : %d\n",UA_Max());

    printf("Minimum Element          : %d\n",UA_Min());

    printf("Predecessor of 500       : %d\n",UA_Predecessor(500));

    printf("Successor of 500         : %d\n",UA_Successor(500));

    printf("Current Array Size       : %d\n",uaSize);

    printf("=====================================\n");
}


void SA_Insert(int value)
{
    int i = saSize - 1;

    while(i >= 0 && sortedArray[i] > value)
    {
        saComp++;
        sortedArray[i + 1] = sortedArray[i];
        i--;
    }

    sortedArray[i + 1] = value;
    saSize++;
}


int SA_Search(int key)
{
    int low = 0;
    int high = saSize - 1;
    int mid;

    while(low <= high)
    {
        saComp++;

        mid = (low + high) / 2;

        if(sortedArray[mid] == key)
            return mid;

        if(sortedArray[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}


void SA_Delete(int key)
{
    int pos = SA_Search(key);

    if(pos == -1)
        return;

    int i;

    for(i = pos; i < saSize - 1; i++)
    {
        saComp++;
        sortedArray[i] = sortedArray[i + 1];
    }

    saSize--;
}



int SA_Max()
{
    saComp++;
    return sortedArray[saSize - 1];
}



int SA_Min()
{
    saComp++;
    return sortedArray[0];
}


int SA_Predecessor(int key)
{
    int pos = SA_Search(key);

    if(pos <= 0)
        return -1;

    saComp++;

    return sortedArray[pos - 1];
}


int SA_Successor(int key)
{
    int pos = SA_Search(key);

    if(pos == -1 || pos == saSize - 1)
        return -1;

    saComp++;

    return sortedArray[pos + 1];
}


void SA_Display()
{
    int i;

    printf("\nSorted Array : ");

    for(i = 0; i < saSize; i++)
    {
        printf("%d ", sortedArray[i]);
    }

    printf("\n");
}


void SA_Test(int n)
{
    int i;

    saSize = 0;

    for(i = 1; i <= n; i++)
    {
        SA_Insert(rand() % 1000);
    }

    SA_Search(500);

    SA_Max();

    SA_Min();

    SA_Predecessor(500);

    SA_Successor(500);

    SA_Delete(500);

    printf("\n=====================================\n");

    printf("SORTED ARRAY\n");

    printf("=====================================\n");

    printf("Input Size               : %d\n", n);

    printf("Comparisons Performed    : %ld\n", saComp);

    printf("Maximum Element          : %d\n", SA_Max());

    printf("Minimum Element          : %d\n", SA_Min());

    printf("Predecessor of 500       : %d\n", SA_Predecessor(500));

    printf("Successor of 500         : %d\n", SA_Successor(500));

    printf("Current Array Size       : %d\n", saSize);

    printf("=====================================\n");
}


/* Insert at Beginning */

void SLLU_Insert(int value)
{
    SNode *temp = createSNode(value);

    temp->next = SUHead;

    SUHead = temp;

    slluComp++;
}

/* Search */

SNode* SLLU_Search(int key)
{
    SNode *ptr = SUHead;

    while(ptr != NULL)
    {
        slluComp++;

        if(ptr->data == key)
            return ptr;

        ptr = ptr->next;
    }

    return NULL;
}

/* Delete */

void SLLU_Delete(int key)
{
    SNode *ptr = SUHead;
    SNode *prev = NULL;

    while(ptr != NULL)
    {
        slluComp++;

        if(ptr->data == key)
        {
            if(prev == NULL)
                SUHead = ptr->next;
            else
                prev->next = ptr->next;

            free(ptr);
            return;
        }

        prev = ptr;
        ptr = ptr->next;
    }
}

/* Maximum */

int SLLU_Max()
{
    SNode *ptr = SUHead;

    int max = ptr->data;

    while(ptr != NULL)
    {
        slluComp++;

        if(ptr->data > max)
            max = ptr->data;

        ptr = ptr->next;
    }

    return max;
}

/* Minimum */

int SLLU_Min()
{
    SNode *ptr = SUHead;

    int min = ptr->data;

    while(ptr != NULL)
    {
        slluComp++;

        if(ptr->data < min)
            min = ptr->data;

        ptr = ptr->next;
    }

    return min;
}

/* Predecessor */

int SLLU_Predecessor(int key)
{
    SNode *ptr = SUHead;

    int pred = -1;

    while(ptr != NULL)
    {
        slluComp++;

        if(ptr->data < key)
        {
            if(pred == -1 || ptr->data > pred)
                pred = ptr->data;
        }

        ptr = ptr->next;
    }

    return pred;
}

/* Successor */

int SLLU_Successor(int key)
{
    SNode *ptr = SUHead;

    int succ = -1;

    while(ptr != NULL)
    {
        slluComp++;

        if(ptr->data > key)
        {
            if(succ == -1 || ptr->data < succ)
                succ = ptr->data;
        }

        ptr = ptr->next;
    }

    return succ;
}

/* Sorted Insert */

void SLLS_Insert(int value)
{
    SNode *temp = createSNode(value);

    if(SSHead == NULL || value < SSHead->data)
    {
        temp->next = SSHead;
        SSHead = temp;
        sllsComp++;
        return;
    }

    SNode *ptr = SSHead;

    while(ptr->next != NULL && ptr->next->data < value)
    {
        sllsComp++;
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    ptr->next = temp;
}

/* Search */

SNode* SLLS_Search(int key)
{
    SNode *ptr = SSHead;

    while(ptr != NULL)
    {
        sllsComp++;

        if(ptr->data == key)
            return ptr;

        if(ptr->data > key)
            break;

        ptr = ptr->next;
    }

    return NULL;
}

/* Delete */

void SLLS_Delete(int key)
{
    SNode *ptr = SSHead;
    SNode *prev = NULL;

    while(ptr != NULL)
    {
        sllsComp++;

        if(ptr->data == key)
        {
            if(prev == NULL)
                SSHead = ptr->next;
            else
                prev->next = ptr->next;

            free(ptr);
            return;
        }

        prev = ptr;
        ptr = ptr->next;
    }
}

/* Maximum */

int SLLS_Max()
{
    SNode *ptr = SSHead;

    while(ptr->next != NULL)
    {
        sllsComp++;
        ptr = ptr->next;
    }

    return ptr->data;
}

/* Minimum */

int SLLS_Min()
{
    sllsComp++;
    return SSHead->data;
}

/* Predecessor */

int SLLS_Predecessor(int key)
{
    SNode *ptr = SSHead;

    int pred = -1;

    while(ptr != NULL && ptr->data < key)
    {
        sllsComp++;
        pred = ptr->data;
        ptr = ptr->next;
    }

    return pred;
}

/* Successor */

int SLLS_Successor(int key)
{
    SNode *ptr = SSHead;

    while(ptr != NULL)
    {
        sllsComp++;

        if(ptr->data > key)
            return ptr->data;

        ptr = ptr->next;
    }

    return -1;
}


/* Insert at Beginning */

void DLLU_Insert(int value)
{
    DNode *temp = createDNode(value);

    temp->next = DUHead;

    if(DUHead != NULL)
        DUHead->prev = temp;

    DUHead = temp;

    dlluComp++;
}

/* Search */

DNode *DLLU_Search(int key)
{
    DNode *ptr = DUHead;

    while(ptr != NULL)
    {
        dlluComp++;

        if(ptr->data == key)
            return ptr;

        ptr = ptr->next;
    }

    return NULL;
}

/* Delete */

void DLLU_Delete(int key)
{
    DNode *ptr = DLLU_Search(key);

    if(ptr == NULL)
        return;

    if(ptr->prev != NULL)
        ptr->prev->next = ptr->next;
    else
        DUHead = ptr->next;

    if(ptr->next != NULL)
        ptr->next->prev = ptr->prev;

    free(ptr);
}

/* Maximum */

int DLLU_Max()
{
    DNode *ptr = DUHead;

    int max = ptr->data;

    while(ptr != NULL)
    {
        dlluComp++;

        if(ptr->data > max)
            max = ptr->data;

        ptr = ptr->next;
    }

    return max;
}

/* Minimum */

int DLLU_Min()
{
    DNode *ptr = DUHead;

    int min = ptr->data;

    while(ptr != NULL)
    {
        dlluComp++;

        if(ptr->data < min)
            min = ptr->data;

        ptr = ptr->next;
    }

    return min;
}

/* Predecessor */

int DLLU_Predecessor(int key)
{
    DNode *ptr = DUHead;

    int pred = -1;

    while(ptr != NULL)
    {
        dlluComp++;

        if(ptr->data < key)
        {
            if(pred == -1 || ptr->data > pred)
                pred = ptr->data;
        }

        ptr = ptr->next;
    }

    return pred;
}

/* Successor */

int DLLU_Successor(int key)
{
    DNode *ptr = DUHead;

    int succ = -1;

    while(ptr != NULL)
    {
        dlluComp++;

        if(ptr->data > key)
        {
            if(succ == -1 || ptr->data < succ)
                succ = ptr->data;
        }

        ptr = ptr->next;
    }

    return succ;
}


/* Sorted Insert */

void DLLS_Insert(int value)
{
    DNode *temp = createDNode(value);

    if(DSHead == NULL)
    {
        DSHead = temp;
        dllsComp++;
        return;
    }

    if(value < DSHead->data)
    {
        temp->next = DSHead;
        DSHead->prev = temp;
        DSHead = temp;
        dllsComp++;
        return;
    }

    DNode *ptr = DSHead;

    while(ptr->next != NULL && ptr->next->data < value)
    {
        dllsComp++;
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    temp->prev = ptr;

    if(ptr->next != NULL)
        ptr->next->prev = temp;

    ptr->next = temp;
}

/* Search */

DNode *DLLS_Search(int key)
{
    DNode *ptr = DSHead;

    while(ptr != NULL)
    {
        dllsComp++;

        if(ptr->data == key)
            return ptr;

        if(ptr->data > key)
            break;

        ptr = ptr->next;
    }

    return NULL;
}

/* Delete */

void DLLS_Delete(int key)
{
    DNode *ptr = DLLS_Search(key);

    if(ptr == NULL)
        return;

    if(ptr->prev != NULL)
        ptr->prev->next = ptr->next;
    else
        DSHead = ptr->next;

    if(ptr->next != NULL)
        ptr->next->prev = ptr->prev;

    free(ptr);
}

/* Maximum */

int DLLS_Max()
{
    DNode *ptr = DSHead;

    while(ptr->next != NULL)
    {
        dllsComp++;
        ptr = ptr->next;
    }

    return ptr->data;
}

/* Minimum */

int DLLS_Min()
{
    dllsComp++;
    return DSHead->data;
}

/* Predecessor */

int DLLS_Predecessor(int key)
{
    DNode *ptr = DSHead;

    int pred = -1;

    while(ptr != NULL && ptr->data < key)
    {
        dllsComp++;
        pred = ptr->data;
        ptr = ptr->next;
    }

    return pred;
}

/* Successor */

int DLLS_Successor(int key)
{
    DNode *ptr = DSHead;

    while(ptr != NULL)
    {
        dllsComp++;

        if(ptr->data > key)
            return ptr->data;

        ptr = ptr->next;
    }

    return -1;
}


void DLL_Display(DNode *head)
{
    DNode *ptr = head;

    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}


void GenerateData(int n)
{
    int i;

    uaSize = 0;
    saSize = 0;

    SUHead = NULL;
    SSHead = NULL;

    DUHead = NULL;
    DSHead = NULL;

    for(i = 1; i <= n; i++)
    {
        int value = rand() % 1000 + 1;

        UA_Insert(value);

        SA_Insert(value);

        SLLU_Insert(value);

        SLLS_Insert(value);

        DLLU_Insert(value);

        DLLS_Insert(value);
    }
}



void PerformOperations()
{
    UA_Search(500);
    UA_Delete(500);
    UA_Max();
    UA_Min();
    UA_Predecessor(500);
    UA_Successor(500);

    SA_Search(500);
    SA_Delete(500);
    SA_Max();
    SA_Min();
    SA_Predecessor(500);
    SA_Successor(500);

    SLLU_Search(500);
    SLLU_Delete(500);
    SLLU_Max();
    SLLU_Min();
    SLLU_Predecessor(500);
    SLLU_Successor(500);

    SLLS_Search(500);
    SLLS_Delete(500);
    SLLS_Max();
    SLLS_Min();
    SLLS_Predecessor(500);
    SLLS_Successor(500);

    DLLU_Search(500);
    DLLU_Delete(500);
    DLLU_Max();
    DLLU_Min();
    DLLU_Predecessor(500);
    DLLU_Successor(500);

    DLLS_Search(500);
    DLLS_Delete(500);
    DLLS_Max();
    DLLS_Min();
    DLLS_Predecessor(500);
    DLLS_Successor(500);
}


void PrintResult(int n)
{
    printf("\n=============================================\n");

    printf("Input Size : %d\n", n);

    printf("---------------------------------------------\n");

    printf("Unsorted Array Comparisons          : %ld\n", uaComp);

    printf("Sorted Array Comparisons            : %ld\n", saComp);

    printf("Singly LL (Unsorted) Comparisons    : %ld\n", slluComp);

    printf("Singly LL (Sorted) Comparisons      : %ld\n", sllsComp);

    printf("Doubly LL (Unsorted) Comparisons    : %ld\n", dlluComp);

    printf("Doubly LL (Sorted) Comparisons      : %ld\n", dllsComp);

    printf("=============================================\n");
}



void WriteToFile(FILE *fp, int n)
{
    fprintf(fp,
            "%d %ld %ld %ld %ld %ld %ld\n",
            n,
            uaComp,
            saComp,
            slluComp,
            sllsComp,
            dlluComp,
            dllsComp);
}



void GenerateReport()
{
    FILE *fp;

    fp = fopen("dictionary.txt","w");

    fprintf(fp,
    "#N UA SA SLLU SLLS DLLU DLLS\n");

    int n;

    for(n = 100; n <= 1000; n += 100)
    {
        resetCounters();

        GenerateData(n);

        PerformOperations();

        PrintResult(n);

        WriteToFile(fp,n);
    }

    fclose(fp);

    printf("\n");

    printf("=============================================\n");

    printf("dictionary.txt created successfully.\n");

    printf("All comparison values stored.\n");

    printf("=============================================\n");
}


void PlotGraph()
{
    FILE *gnuplot;

    printf("\n");
    printf("===============================================\n");
    printf("Launching GNUplot...\n");
    printf("Please wait...\n");
    printf("===============================================\n");

    gnuplot = popen("gnuplot -persistent","w");

    if(gnuplot == NULL)
    {
        printf("\nError Opening GNUplot!\n");
        return;
    }

    /* Graph Title */

    fprintf(gnuplot,
    "set title 'Dictionary Operations Analysis'\n");

    /* Labels */

    fprintf(gnuplot,
    "set xlabel 'Input Size (N)'\n");

    fprintf(gnuplot,
    "set ylabel 'Number of Comparisons'\n");

    /* Grid */

    fprintf(gnuplot,
    "set grid\n");

    /* Legend */

    fprintf(gnuplot,
    "set key outside\n");

    /* Line Width */

    fprintf(gnuplot,
    "set style line 1 lw 2\n");

    fprintf(gnuplot,
    "set style line 2 lw 2\n");

    fprintf(gnuplot,
    "set style line 3 lw 2\n");

    fprintf(gnuplot,
    "set style line 4 lw 2\n");

    fprintf(gnuplot,
    "set style line 5 lw 2\n");

    fprintf(gnuplot,
    "set style line 6 lw 2\n");

    /* Output Window Size */

    fprintf(gnuplot,
    "set term wxt size 900,600\n");

    /* Plot Commands */

    fprintf(gnuplot,
    "plot "
    "'dictionary.txt' using 1:2 with linespoints ls 1 title 'Unsorted Array',"
    "'dictionary.txt' using 1:3 with linespoints ls 2 title 'Sorted Array',"
    "'dictionary.txt' using 1:4 with linespoints ls 3 title 'Singly LL (Unsorted)',"
    "'dictionary.txt' using 1:5 with linespoints ls 4 title 'Singly LL (Sorted)',"
    "'dictionary.txt' using 1:6 with linespoints ls 5 title 'Doubly LL (Unsorted)',"
    "'dictionary.txt' using 1:7 with linespoints ls 6 title 'Doubly LL (Sorted)'\n");

    fflush(gnuplot);

    pclose(gnuplot);

    printf("\n");
    printf("===============================================\n");
    printf("Graph Generated Successfully.\n");
    printf("dictionary.txt plotted successfully.\n");
    printf("GNUplot executed successfully.\n");
    printf("===============================================\n");
}


void ShowFile()
{
    FILE *fp;

    char ch;

    fp = fopen("dictionary.txt","r");

    if(fp == NULL)
    {
        printf("\nUnable to open dictionary.txt\n");
        return;
    }

    printf("\n");
    printf("===============================================\n");
    printf("Contents of dictionary.txt\n");
    printf("===============================================\n\n");

    while((ch=fgetc(fp))!=EOF)
    {
        putchar(ch);
    }

    fclose(fp);

    printf("\n");
    printf("===============================================\n");
}


int main()
{
    int choice;

    srand(time(NULL));

    printHeading();

    printf("\n");

    printf("===============================================\n");
    printf("      DESIGN AND ANALYSIS OF ALGORITHMS\n");
    printf("===============================================\n");

    printf("\nDictionary Operations Analysis\n");

    printf("\nData Structures Used\n");

    printf("1. Unsorted Array\n");
    printf("2. Sorted Array\n");
    printf("3. Singly Linked List (Unsorted)\n");
    printf("4. Singly Linked List (Sorted)\n");
    printf("5. Doubly Linked List (Unsorted)\n");
    printf("6. Doubly Linked List (Sorted)\n");

    printf("\n===============================================\n");

    printf("Press 1 to Start Analysis : ");

    scanf("%d",&choice);

    if(choice!=1)
    {
        printf("\nProgram Terminated.\n");
        return 0;
    }

    printf("\n");

    printf("Generating Random Data......\n");

    printf("Please Wait...\n");

    printf("\n");

    GenerateReport();

    printf("\n");

    printf("Displaying Generated File...\n");

    ShowFile();

    printf("\n");

    PlotGraph();

    printf("\n");

    printf("===============================================\n");

    printf("SUMMARY\n");

    printf("===============================================\n");

    printf("All Dictionary Operations Executed Successfully.\n");

    printf("Comparison Counts Calculated.\n");

    printf("dictionary.txt Generated.\n");

    printf("GNUplot Graph Generated Successfully.\n");

    printf("Program Executed Successfully.\n");

    printf("===============================================\n");

    printf("\n");

    printf("THANK YOU\n");

    printf("\n");

    return 0;
}