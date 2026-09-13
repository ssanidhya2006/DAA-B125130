#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter number of hiding spots: ");
    scanf("%d", &n);

    printf("\nGuaranteed Shooting Sequence:\n");

    // Forward sweep
    for(i=2;i<=n-1;i++)
        printf("Shoot at Spot %d\n", i);

    // Backward sweep
    for(i=n-1;i>=2;i--)
        printf("Shoot at Spot %d\n", i);

    printf("\nTarget is guaranteed to be hit.\n");

    return 0;
}