#include <stdio.h>
#include <stdlib.h>

struct Interval{
    int start,end;
};

int compare(const void *a,const void *b){
    return ((struct Interval*)a)->start-
           ((struct Interval*)b)->start;
}

int main(){

    int n;

    printf("Enter intervals: ");
    scanf("%d",&n);

    struct Interval a[n];

    for(int i=0;i<n;i++)
        scanf("%d%d",&a[i].start,&a[i].end);

    qsort(a,n,sizeof(struct Interval),compare);

    struct Interval current=a[0];

    printf("Merged Intervals:\n");

    for(int i=1;i<n;i++){

        if(a[i].start<=current.end){

            if(a[i].end>current.end)
                current.end=a[i].end;
        }

        else{

            printf("(%d,%d)\n",
                    current.start,current.end);

            current=a[i];
        }
    }

    printf("(%d,%d)",current.start,current.end);
}