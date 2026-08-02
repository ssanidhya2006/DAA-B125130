#include<stdio.h>
int main(){
    int n,i,j;
    int a[100];
    int dup=0;

    printf("enter no of elements:");
    scanf("%d",&n);

    printf("enter elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++){
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[i]==a[j]){
                dup=1;
            }
        }
    }
    
}

if(dup==1)
  printf("duplicate elements found");
else
  printf("all elements are unique");
  
  return 0;

}