// Practical 7 Aim:Write a Program to implement Quicksort using Divide and Conquer approach
#include <stdio.h>
int partition(int a[], int l, int u)
{
    int v, i, j, temp;
    v = a[l]; // pivot
    i = l;
    j = u + 1;
    do
    {
        do
            i++;
        while (a[i] < v && i <= u);
        do
            j--;
        while (a[j] > v);
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    a[l] = a[j];
    a[j] = v;
    return (j);
}
void quick_sort(int a[], int l, int u)
{
    int j;
    if (l < u)
    {
        j = partition(a, l, u);
        quick_sort(a, l, j - 1);
        quick_sort(a, j + 1, u);
    }
}
void main()
{
    int a[30], n, i, j;
    printf("\nEnter no of elements:");
    scanf("%d", &n);

    printf("\nEnter array elements:");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quick_sort(a, 0, n - 1);
    printf("\nSorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
}
/*
Output:
Enter no of elements:7

Enter array elements:20 89 40 78 90 12 34

Sorted array is: 12     20      34      40      78      89      90
*/