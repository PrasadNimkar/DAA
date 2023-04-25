// Practical 4 Aim:Write a program to implement Binary Search using recursion.
#include <stdio.h>
int binarySearch(int arr[], int l, int x, int h)
{
  if (h >= l)
  {
    int mid = (l + h) / 2;
    if (arr[mid] == x)
      return mid;
    if (arr[mid] > x)
      return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, x, h);
  }
  return -1;
}
int main()
{
  int arr[] = {2, 4, 6, 8, 7, 9, 10};
  int x = 10;
  int l = 0;
  int n = sizeof(arr) / sizeof(arr[0]);
  int h = n - 1;
  int res = binarySearch(arr, l, x, h);
  if (res == -1)
  {
    printf("Element is not present in array");
  }
  else
  {
    printf("Element is present at index %d", res);
    return 0;
  }
}
/*
Output:
Element is present at index 6
*/