#include <stdio.h>
#include <stdlib.h>

struct Event{
    int time;
    int change;
};

int compare(const void *a,const void *b){
    return ((struct Event*)a)->time-
           ((struct Event*)b)->time;
}

int main(){

    int n;

    printf("Enter people: ");
    scanf("%d",&n);

    struct Event e[2*n];

    for(int i=0;i<n;i++){

        scanf("%d%d",&e[2*i].time,
                    &e[2*i+1].time);

        e[2*i].change=1;
        e[2*i+1].change=-1;
    }

    qsort(e,2*n,sizeof(struct Event),compare);

    int current=0,max=0,time=0;

    for(int i=0;i<2*n;i++){

        current+=e[i].change;

        if(current>max){

            max=current;
            time=e[i].time;
        }
    }

    printf("Maximum People = %d\n",max);
    printf("Time = %d",time);
}