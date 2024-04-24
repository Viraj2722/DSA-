#include <stdio.h>

int sumofsubsets(int s, int k, int r, int *w, int m, int n, int *x)
{
    if (s == m && k == n)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d", x[i]);
        }
        printf("\n");
    }
    x[k] = 1;
    if (s + w[k] == m)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d", x[i]);
        }
        printf("\n");
    }
    else if (s + w[k] + w[k + 1] <= m)
    {
        sumofsubsets(s + w[k], k + 1, r - w[k], w, m, n, x);
    }

    if (s + w[k + 1] <= m && s - w[k] + r >= m)
    {
        x[k] = 0;
        sumofsubsets(s, k + 1, r - w[k], w, m, n, x);
    }
}
int main()
{
    int m, n, r = 0;
    printf("Enter the target sum: ");
    scanf("%d", &m);
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int w[n + 1], x[n + 1];
    w[0] = 0;
    x[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
        r += w[i];
        x[i] = 0;
    }

    if (m > r)
    {
        return;
    }
    sumofsubsets(0, 1, r, w, m, n, x);
}