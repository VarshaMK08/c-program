#include <stdio.h>

int getMax(int a[], int n)
{
    int max = a[0], i;
    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

int countSort(int a[], int n, int exp)
{
    int output[20], count[10] = {0};
    int i;
    for (i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        a[i] = output[i];
}

int radixSort(int a[], int n)
{
    int exp, max = getMax(a, n);

    for (exp = 1; max / exp > 0; exp *= 10)
        countSort(a, n, exp);
}

int main()
{
    int i, n, a[50];

    printf("Enter the number elements to be sorted: ");
    scanf("%d", &n);

    printf("Enter the values : ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    radixSort(a, n);

    printf("\nSorted Array\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}