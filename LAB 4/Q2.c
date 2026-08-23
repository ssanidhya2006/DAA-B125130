#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b){
    return (*(int*)a-*(int*)b);
}

int main(){

    int n,x;

    printf("Enter size: ");
    scanf("%d",&n);

    int s1[n],s2[n];

    printf("Enter Set 1:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&s1[i]);

    printf("Enter Set 2:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&s2[i]);

    printf("Enter target: ");
    scanf("%d",&x);

    qsort(s2,n,sizeof(int),compare);

    for(int i=0;i<n;i++){

        int left=0,right=n-1;

        while(left<=right){

            int mid=(left+right)/2;

            if(s2[mid]==x-s1[i]){

                printf("Pair Found: %d + %d = %d",
                        s1[i],s2[mid],x);
                return 0;
            }

            if(s2[mid]<x-s1[i])
                left=mid+1;
            else
                right=mid-1;
        }
    }

    printf("No Pair Found");

    return 0;
}