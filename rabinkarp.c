#include <stdio.h>
#include <string.h>

#define d 10

void rabinkarp(char pattern[], char text[], int q)
{
    int m = strlen(pattern);
    int n = strlen(text);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }
    for (int i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    break;
                }
            }
            if (j == m)
            {
                printf("Pattern is found at position : %d", i);
            }
        }
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
            {
                t = (t + q);
            }
        }
    }
}

int main()
{
    char text[30], pattern[30];
    printf("Enter the text:");
    scanf("%s", &text);
    printf("Enter the pattern:");
    scanf("%s", &pattern);
    int q = 13;
    rabinkarp(pattern, text, q);
    return 0;
}
