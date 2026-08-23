#include <stdio.h>
#include <stdlib.h>

struct Event{
    int point;
    int type;
};

int compare(const void *a,const void *b){

    struct Event *x=(struct Event*)a;
    struct Event *y=(struct Event*)b;

    if(x->point==y->point)
        return y->type-x->type;

    return x->point-y->point;
}

int main(){

    int n;

    printf("Enter intervals: ");
    scanf("%d",&n);

    struct Event e[2*n];

    for(int i=0;i<n;i++){

        scanf("%d%d",&e[2*i].point,
                    &e[2*i+1].point);

        e[2*i].type=1;
        e[2*i+1].type=-1;
    }

    qsort(e,2*n,sizeof(struct Event),compare);

    int current=0,max=0,answer=0;

    for(int i=0;i<2*n;i++){

        current+=e[i].type;

        if(current>max){

            max=current;
            answer=e[i].point;
        }
    }

    printf("Point = %d\n",answer);
    printf("Maximum Overlap = %d",max);
}