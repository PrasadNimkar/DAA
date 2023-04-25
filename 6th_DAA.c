// Practical 6 Aim:Develop a program to print all node reachable from starting node using DFS.
#include <stdio.h>
int p[10][10], reach[20], n;
void dfs(int v)
{
    int i;
    reach[v] = 1;
    for (i = 1; i <= n; i++)
    {
        if (p[v][i] && !reach[i])
        {
            printf("\n %d--->%d", v, i);
            dfs(i);
        }
    }
}
void main()
{
    int i, j;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacent matrix: ");
    printf("\nEnter zero for self loop & 999 nor no edge: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    dfs(1);
}
/*
Output:
Enter the number of vertices: 6

Enter the adjacent matrix:
Enter zero for self loop & 999 nor no edge:
0 1 0 1 0 0
0 0 1 0 1 0
0 0 0 0 1 1
0 1 0 0 0 0
0 0 0 1 0 0
0 0 0 0 0 1

 1--->2
 2--->3
 3--->5
 5--->4
 3--->6
 */