#include <stdio.h>

int main()
{
    int n, i, j;
    printf("Enter the size of array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Entered array is : \n");
    for (j = 0; j < n; j++)
    {
        printf("%d\t", arr[j]);
    }

    for (int i = 0; i < n; i++)
    {
        int min = arr[i];
        int pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                pos = j;
            }
        }
        printf("After %d pass : \n", i);
        for (int l = 0; l < n; l++)
        {
            printf("%d\t", arr[l]);
        }
        printf("\n");
        arr[pos] = arr[i];
        arr[i] = min;
    }
    printf("Sorted array is : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}
