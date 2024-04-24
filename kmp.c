#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void kmp(char *string, char *pattern, int ptr[])
{
    int i = 0, j = 0;
    while (i + j < strlen(string))
    {
        if (string[i + j] == pattern[j])
        {
            if (j == strlen(pattern) - 1)
            {
                printf("%d", i);
            }
            j++;
        }
        else
        {
            i += j - ptr[j];
            if (ptr[j] > -1)
            {
                j = ptr[j];
            }
            else
            {
                j = 0;
            }
        }
    }
}

void find_overlap(char *pattern, int ptr[])
{
    int i = 2, j = 0;
    ptr[0] = -1;
    ptr[1] = 0;

    while (i <= strlen(pattern))
    {
        if (pattern[i - 1] == pattern[j])
        {
            j++;
            ptr[i] = j;
            i++;
        }
        else if (j > 0)
        {
            j = ptr[j];
        }
        else
        {
            ptr[i] = 0;
            i++;
        }
    }
}

void main()
{
    char string[100], pattern[100];
    int ptr[100];
    fgets(string, 100, stdin);
    pattern[strlen(pattern) - 1] = '\0';
    fgets(pattern, 100, stdin);
    pattern[strlen(pattern) - 1] = '\0';
    find_overlap(pattern, ptr);
    for (int i = 1; i <= strlen(pattern); i++)
    {
        printf("%d ", ptr[i]);
    }
    kmp(string, pattern, ptr);
}