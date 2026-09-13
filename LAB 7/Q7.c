#include <stdio.h>

int m[20][20];
int s[20][20];

void printOrder(int i, int j)
{
    if(i==j)
    {
        printf("A%d", i);
        return;
    }

    printf("(");
    printOrder(i, s[i][j]);
    printOrder(s[i][j]+1, j);
    printf(")");
}

int main()
{
    int n, i, j, k, L, q;
    int p[20];

    printf("Enter number of matrices: ");
    scanf("%d",&n);

    printf("Enter %d dimensions: ", n+1);

    for(i=0;i<=n;i++)
        scanf("%d",&p[i]);

    for(i=1;i<=n;i++)
        m[i][i]=0;

    for(L=2;L<=n;L++)
    {
        for(i=1;i<=n-L+1;i++)
        {
            j=i+L-1;
            m[i][j]=999999;

            for(k=i;k<j;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];

                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }

    printf("\nMinimum Scalar Multiplications = %d\n", m[1][n]);

    printf("Optimal Order = ");
    printOrder(1,n);

    printf("\n");

    return 0;
}