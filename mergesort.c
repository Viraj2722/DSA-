#include <stdio.h>
int z = 1;
int merge(int arr[], int l, int m, int r, int length)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    printf("After merge %d \n", z);
    for (int o = 0; o < length; o++)
    {
        printf("%d\t", arr[o]);
    }
    z++;
    printf("\n");
}

int mergesort(int arr[], int l, int r, int length)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m, length);
        mergesort(arr, m + 1, r, length);
        merge(arr, l, m, r, length);
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
    mergesort(arr, 0, n - 1, n);

    printf("sorted array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}