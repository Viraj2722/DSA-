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
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
        printf("After %d pass :\n", i + 1);
        for (int l = 0; l < n; l++)
        {
            printf("%d\t", arr[l]);
        }
        printf("\n");
    }
    printf("sorted array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}