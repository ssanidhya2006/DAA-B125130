#include <stdio.h>
#include <stdlib.h>

struct Event
{
    int year;
    int type;      // -1 = death, +1 = birth
};

int compare(const void *a, const void *b)
{
    struct Event *x = (struct Event *)a;
    struct Event *y = (struct Event *)b;

    if(x->year != y->year)
        return x->year - y->year;

    return x->type - y->type;   // death (-1) comes before birth (+1)
}

int main()
{
    int n, i;
    printf("Enter number of scientists: ");
    scanf("%d", &n);

    struct Event events[200];

    for(i=0;i<n;i++)
    {
        int birth, death;

        printf("Enter birth and death year of Scientist %d: ", i+1);
        scanf("%d %d", &birth, &death);

        events[2*i].year = birth;
        events[2*i].type = 1;

        events[2*i+1].year = death;
        events[2*i+1].type = -1;
    }

    qsort(events, 2*n, sizeof(struct Event), compare);

    int alive = 0;
    int maxAlive = 0;
    int bestYear = 0;

    for(i=0;i<2*n;i++)
    {
        alive += events[i].type;

        if(alive > maxAlive)
        {
            maxAlive = alive;
            bestYear = events[i].year;
        }
    }

    printf("\nBest Year = %d\n", bestYear);
    printf("Maximum Scientists Alive = %d\n", maxAlive);

    return 0;
}