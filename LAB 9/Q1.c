#include <stdio.h>

struct Item
{
    float value;
    float weight;
    float decay;
    int used;
};

int main()
{
    struct Item item[100];
    int n, i, t;
    float capacity, remaining, density;
    float totalValue = 0;
    int best;

    printf("Enter number of items: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Invalid number of items.\n");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nEnter base value of item %d: ", i + 1);
        scanf("%f", &item[i].value);

        printf("Enter weight of item %d: ", i + 1);
        scanf("%f", &item[i].weight);

        printf("Enter decay rate of item %d: ", i + 1);
        scanf("%f", &item[i].decay);

        if (item[i].value < 0 || item[i].weight <= 0 ||
            item[i].decay < 0)
        {
            printf("Invalid item data.\n");
            return 0;
        }

        item[i].used = 0;
    }

    printf("\nEnter knapsack capacity: ");
    scanf("%f", &capacity);

    if (capacity <= 0)
    {
        printf("Invalid capacity.\n");
        return 0;
    }

    remaining = capacity;
    t = 0;

    printf("\nSelected items:\n");

    while (remaining > 0)
    {
        best = -1;
        density = 0;

        // Find the item with the highest current density
        for (i = 0; i < n; i++)
        {
            if (item[i].used == 0)
            {
                float current = item[i].value / item[i].weight
                                - item[i].decay * t;

                if (current > density)
                {
                    density = current;
                    best = i;
                }
            }
        }

        // Stop if no positive-density item remains
        if (best == -1)
            break;

        // Take the whole item or a fraction of it
        float taken = item[best].weight;

        if (taken > remaining)
            taken = remaining;

        float fraction = taken / item[best].weight;
        float gained = taken * density;

        printf("Item %d: weight taken = %.2f, fraction = %.2f, "
               "effective density = %.2f, value gained = %.2f\n",
               best + 1, taken, fraction, density, gained);

        totalValue += gained;
        remaining -= taken;
        item[best].used = 1;
        t++;
    }

    printf("\nTotal weight used = %.2f\n", capacity - remaining);
    printf("Unused capacity = %.2f\n", remaining);
    printf("Total value obtained = %.2f\n", totalValue);

    return 0;
}