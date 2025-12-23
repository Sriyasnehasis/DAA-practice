#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int low, int high)
{
    int pivot = a[low]; // first element as pivot
    int i = low + 1, j = high;

    while (1)
    {
        while (i <= high && a[i] <= pivot)
            i++;
        while (j >= low && a[j] > pivot)
            j--;
        if (i < j)
            swap(&a[i], &a[j]);
        else
            break;
    }
    swap(&a[low], &a[j]); // place pivot in correct position
    return j;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main()
{
    int n, i;
    printf("Enter n: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quickSort(a, 0, n - 1);

    printf("Sorted: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
