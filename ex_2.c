// Practical 2
#include <stdio.h>
#include <stdlib.h>
void knapsack(int n, float w[], float p[], int M)
{
    float x[20], tp = 0;
    int i, j, u;
    u = M;
    for (i = 0; i < n; i++)
        x[i] = 0.0;
    for (i = 0; i < n; i++)
    {
        if (w[i] > u)
        {
            break;
        }
        else
        {
            x[i] = 1.0;
            tp = tp + p[i];
            u = u - w[i];
        }
    }
    if (i < n)
        x[i] = u / w[i];
    tp = tp + (x[i] * p[i]);
    printf("\n The resultant vector is: ");
    for (i = 0; i < n; i++)
        printf("%f \t", x[i]);
    printf("\n The Maximum profit is : %f", tp);
}
int main()
{
    int n, item[50], M, i, j;
    float ratio[50], w[50], p[50], temp;
    printf("Enter the number of items :: ");
    scanf("%d", &n);

    printf("Enter the capacity of knapsack :: ");
    scanf("%d", &M);

    printf("Enter the weights and value of each items::\n");
    printf("Item\tWeights\tProfit\n");
    printf("---------------------------\n");
    for (i = 0; i < n; i++)
    {
        item[i] = i + 1;
        printf("I[%d]\t", item[i]);
        scanf("%f", &w[i]);
        scanf("%f", &p[i]);
    }
    for (i = 0; i < n; i++)
    {
        ratio[i] = (p[i] / w[i]);
    }
    printf("\n");
    printf("Item\tWeights\tProfit\tRatio(pi)\n");
    printf("-----------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf("I[%d]\t", item[i]);
        printf("%f\t", w[i]);
        printf("%f\t", p[i]);
        printf("%f\n", ratio[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        for (j = 1 + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = w[j];
                w[j] = w[i];
                w[i] = temp;

                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }
    knapsack(n, w, p, M);
    return 0;
}
/*Output:
Enter the number of items :: 3
Enter the capacity of knapsack :: 20
Enter the weights and value of each items::
Item    Weights Profit
---------------------------
I[1]    18 25
I[2]    15 24
I[3]    10 15

Item    Weights Profit  Ratio(pi)
-----------------------------
I[1]    18.000000       25.000000       1.388889
I[2]    15.000000       24.000000       1.600000
I[3]    10.000000       15.000000       1.500000


 The resultant vector is: 1.000000      0.666667        0.000000
 The Maximum profit is : 31.000000
*/