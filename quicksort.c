#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    printf("Partition Pass: Pivot = %d\n", pivot);
    printf("Array: ");
    for (int k = low; k <= high; k++)
    {
        printf("%d ", arr[k]);
    }
    printf("\n");

    while (i <= j)
    {
        while (arr[i] <= pivot && i <= high)
        {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }

        if (i <= j)
        {
            swap(&arr[i], &arr[j]);
            printf("Swapping %d and %d:\t", arr[i], arr[j]);
            for (int k = low; k <= high; k++)
            {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
    }

    swap(&arr[low], &arr[j]);
    printf("Pivot %d is in its sorted position:\t", pivot);
    for (int k = low; k <= high; k++)
    {
        printf("%d ", arr[k]);
    }
    printf("\n\n");

    return j;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int main()
{
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nInitial Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    quicksort(arr, 0, n - 1);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
