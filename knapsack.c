#include <stdio.h>
#define MAX 100

int main()
{
    int n, flag[MAX] = {0}, v[MAX], w[MAX], m[MAX][MAX], W, i, j, k;
    printf("Enter the number of elements ");
    scanf("%d", &n);
    printf("Enter the profit : ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &v[i]);
    }
    printf("Enter the weights : ");
    for (int j = 1; j <= n; j++)
    {
        scanf("%d", &w[j]);
    }
    printf("Enter the maximum weight : ");
    scanf("%d", &W);

    printf("Matrix is : ");
    for (int j = 0; j <= W; j++)
    {
        m[0][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                if (w[i] <= j)
                {
                    if (m[i - 1][j] > m[i - 1][j - w[i]] + v[i])
                    {
                        m[i][j] = m[i - 1][j];
                    }
                    else
                    {
                        m[i][j] = m[i - 1][j - w[i]] + v[i];
                    }
                }
                else
                {
                    m[i][j] = m[i - 1][j];
                }
            }
        }
    }
    i = n;
    k = W;
    while (i > 0 && k > 0)
    {
        if (m[i][k] != m[i - 1][k])
        {
            flag[i] = 1;
            k = k - w[i];
            i = i - 1;
        }
        else
        {
            i--;
        }
    }
    printf("\n");
    for (int i = 0; i <= W; i++)
    {
        printf("%d\t", i);
    }
    printf("\n");
    for (int i = 1; i <= W * 10; i++)
    {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d |\t", i);
        for (int j = 0; j <= W; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Rv is : ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d\t", flag[i]);
    }
    printf("\n");
    printf("The total profit is : %d\n", m[n][W]);

    printf("Objects included are :\n");
    printf("Weights\t Profit\n");
    for (int i = 0; i <= W; i++)
    {
        if (flag[i] == 1)
        {
            printf("\n");
            printf("%d\t", w[i]);
            printf("%d", v[i]);
        }
    }
}
