#include <stdio.h>

int main()
{
    int n, i, j;
    int a[100];
    int dup = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Check for duplicate elements
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] == a[j])
            {
                dup = 1;
                break;
            }
        }

        if(dup == 1)
            break;
    }

    if(dup == 1)
        printf("Duplicate elements found.");
    else
        printf("All elements are unique.");

    return 0;
}
