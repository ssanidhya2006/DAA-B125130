#include <stdio.h>
#include <string.h>

struct Item{
    int num;
    char color[10];
};

int main(){

    int n;

    printf("Enter number of items: ");
    scanf("%d",&n);

    struct Item a[n];

    printf("Enter number and color:\n");

    for(int i=0;i<n;i++)
        scanf("%d %s",&a[i].num,a[i].color);

    printf("\nSorted by Color:\n");

    // Print all Red items
    for(int i=0;i<n;i++)
        if(strcmp(a[i].color,"Red")==0)
            printf("%d %s\n",a[i].num,a[i].color);

    // Print all Blue items
    for(int i=0;i<n;i++)
        if(strcmp(a[i].color,"Blue")==0)
            printf("%d %s\n",a[i].num,a[i].color);

    // Print all Yellow items
    for(int i=0;i<n;i++)
        if(strcmp(a[i].color,"Yellow")==0)
            printf("%d %s\n",a[i].num,a[i].color);

    return 0;
}