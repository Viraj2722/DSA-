#include <stdio.h>
#include <string.h>

int lcs(char str1[], char str2[], int m, int n)
{
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    printf("Matrix is : \n");
    printf(" \t");
    printf(" \t");
    for (int i = 0; i < n; i++)
    {
        printf("%c\t", str2[i]);
    }
    printf("\n");
    for (int i = 0; i <= m; i++)
    {
        if (i == 0)
        {
            printf(" \t");
        }
        else
        {
            printf("%c\t", str1[i - 1]);
        }
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
            {
                printf("0\t");
            }
            else
            {
                printf("%d\t", dp[i][j]);
                if (str1[i - 1] == str2[j - 1])
                {
                    printf("↖\t");
                }
                if (dp[i - 1][j] >= dp[i][j - 1])
                {
                    printf("^\t");
                }
                else
                {
                    printf("<-\t");
                }
            }
        }
        printf("\n");
    }
    int length = dp[m][n];
    char lcs[length + 1];
    lcs[length] = '\0';

    int i = m;
    int j = n;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs[length - 1] = str1[i - 1];
            i--;
            j--;
            length--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    printf("Length of LCS is : %d\n", dp[m][n]);
    printf("LCS sequence is : %s", lcs);
}
int main()
{
    char str1[100];
    char str2[100];
    printf("Enter the first string :");
    scanf("%s", str1);
    printf("Enter the second string :");
    scanf("%s", str2);
    int m = strlen(str1);
    int n = strlen(str2);
    lcs(str1, str2, m, n);
    return 0;
}