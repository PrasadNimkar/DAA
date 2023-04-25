// Practical 3 Aim:Write a program in c to implement Floyd's algorithm which will produce shortest distance between all vertex pair of weighted graph.
#include <stdio.h>
int min(int a, int b)
{
   if (a < b)
      return (a);
   else
      return (b);
}
void floyds(int arr[200][200], int n)
{
   int i, j, k;
   for (k = 1; k <= n; k++)
      for (i = 1; i <= n; i++)
         for (j = 1; j <= n; j++)
            arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
}
void main()
{
   int arr[200][200], n, i, j;
   printf("\nEnter the number of vertices : ");
   scanf("%d", &n);
   printf("\nEnter the adjesent matrix");
   printf("\nEnter 0 for self loop and 999 for infinity node\n");
   for (i = 1; i <= n; i++)
   {
      for (j = 1; j <= n; j++)
      {
         scanf("%d", &arr[i][j]);
      }
   }
   floyds(arr, n);
   printf("\nShortest path is :\n");
   for (i = 1; i <= n; i++)
   {
      for (j = 1; j <= n; j++)
      {
         printf("%d\t", arr[i][j]);
      }
      printf("\n");
   }
}
/*
Output:
Enter the number of vertices : 4

Enter the adjesent matrix
Enter 0 for self loop and 999 for infinity node
0   5    999  999
50  0    15   5
30  999  0    15
15  999  5    0

Shortest path is :
0       5       15      10
20      0       10      5
30      35      0       15
15      20      5       0
*/