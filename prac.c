#include <stdio.h>
#include <string.h>
#define d 10

void rabinkarp(char pattern[], char text[], int q)
{
    int m = strlen(pattern);
    int n = strlen(text);
    int p, t = 0;
    int h = 1;
    int i, j;

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
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    break;
                }
            }
            if (j == m)
            {
                printf("Solution is found At %d position ", i);
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
    char text[30];
    char pattern[30];

    printf("Enter the text : ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);
    int q = 13;
    rabinkarp(pattern, text, q);
}