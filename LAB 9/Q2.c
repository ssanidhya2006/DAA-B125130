#include <stdio.h>
#include <string.h>

#define MAX 100
#define NODES (2 * MAX)
#define BITS (MAX + 5)

struct Node
{
    char symbol;
    long long freq;
    int left, right, parent;
};

struct Node tree[NODES];
int codeLength[MAX];
char code[MAX][BITS];
int order[MAX];

int main()
{
    int n, i, j, total, a, b, x, y, temp;
    long long f;

    printf("Enter number of symbols: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Number of symbols must be between 1 and %d.\n", MAX);
        return 0;
    }

    total = n;

    for (i = 0; i < n; i++)
    {
        printf("Enter symbol %d: ", i + 1);
        scanf(" %c", &tree[i].symbol);

        printf("Enter its frequency: ");
        scanf("%lld", &tree[i].freq);

        if (tree[i].freq <= 0)
        {
            printf("Frequency must be positive.\n");
            return 0;
        }

        tree[i].left = -1;
        tree[i].right = -1;
        tree[i].parent = -1;
    }

    // Step 1: Build the Huffman tree
    while (total < 2 * n - 1)
    {
        a = -1;
        b = -1;

        // Find the two smallest uncombined nodes
        for (i = 0; i < total; i++)
        {
            if (tree[i].parent == -1)
            {
                if (a == -1 || tree[i].freq < tree[a].freq)
                {
                    b = a;
                    a = i;
                }
                else if (b == -1 || tree[i].freq < tree[b].freq)
                {
                    b = i;
                }
            }
        }

        if (b == -1)
            break;

        tree[total].symbol = '#';
        tree[total].freq = tree[a].freq + tree[b].freq;
        tree[total].left = a;
        tree[total].right = b;
        tree[total].parent = -1;

        tree[a].parent = total;
        tree[b].parent = total;

        total++;
    }

    // Step 2: Find each symbol's code length
    for (i = 0; i < n; i++)
    {
        codeLength[i] = 0;
        x = i;

        while (tree[x].parent != -1)
        {
            codeLength[i]++;
            x = tree[x].parent;
        }

        // A single symbol is assigned code 0
        if (n == 1)
            codeLength[i] = 1;

        order[i] = i;
    }

    // Step 3: Sort by code length, then by symbol
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            x = order[i];
            y = order[j];

            if (codeLength[x] > codeLength[y] ||
                (codeLength[x] == codeLength[y] &&
                 tree[x].symbol > tree[y].symbol))
            {
                temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }

    // First canonical code contains only zeros
    x = order[0];

    for (j = 0; j < codeLength[x]; j++)
        code[x][j] = '0';

    code[x][codeLength[x]] = '\0';

    // Generate each next canonical code
    for (i = 1; i < n; i++)
    {
        x = order[i - 1];
        y = order[i];

        strcpy(code[y], code[x]);

        // Increase the previous binary code by one
        j = codeLength[x] - 1;

        while (j >= 0 && code[y][j] == '1')
        {
            code[y][j] = '0';
            j--;
        }

        if (j >= 0)
            code[y][j] = '1';

        // Add zeros if the next code is longer
        for (j = codeLength[x]; j < codeLength[y]; j++)
            code[y][j] = '0';

        code[y][codeLength[y]] = '\0';
    }

    printf("\nCanonical Huffman Codebook\n");
    printf("Symbol\tFrequency\tLength\tCode\n");

    for (i = 0; i < n; i++)
    {
        x = order[i];

        printf("%c\t%lld\t\t%d\t%s\n",
               tree[x].symbol, tree[x].freq,
               codeLength[x], code[x]);
    }

    return 0;
}