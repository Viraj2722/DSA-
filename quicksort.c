#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high, int lenght)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    printf("Pivot is %d \n", arr[i + 1]);
    for (int l = 0; l < lenght; l++)
    {
        printf("%d\t", arr[l]);
    }
    printf("\n");
    return (i + 1);
}

int quicksort(int arr[], int low, int high, int lenght)
{
    if (low < high)
    {
        int p = partition(arr, low, high, lenght);
        quicksort(arr, low, p - 1, lenght);
        quicksort(arr, p + 1, high, lenght);
    }
}

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
    printf("\n");
    quicksort(arr, 0, n - 1, n - 1);

    printf("sorted array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}