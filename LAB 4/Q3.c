#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b){
    return (*(int*)a-*(int*)b);
}

int search(int arr[],int left,int right,int key){

    while(left<=right){

        int mid=(left+right)/2;

        if(arr[mid]==key)
            return 1;

        if(arr[mid]<key)
            left=mid+1;
        else
            right=mid-1;
    }

    return 0;
}

int solve(int arr[],int start,int n,int k,int target){

    if(k==1)
        return search(arr,start,n-1,target);

    for(int i=start;i<=n-k;i++)
        if(solve(arr,i+1,n,k-1,target-arr[i]))
            return 1;

    return 0;
}

int main(){

    int n,k,target;

    printf("Enter size: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter elements:\n");

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("Enter k and target: ");
    scanf("%d%d",&k,&target);

    qsort(arr,n,sizeof(int),compare);

    if(solve(arr,0,n,k,target))
        printf("Possible");
    else
        printf("Not Possible");
}