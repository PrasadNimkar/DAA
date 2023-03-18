// Pratical 1 Aim: Write a program to Implement Tower of Hanoi Problem by using Recursive Functions.
#include <stdio.h>
void toh(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    toh(n - 1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    toh(n - 1, aux_rod, to_rod, from_rod);
}
int main()
{
    int n = 3;
    toh(n, 'A', 'C', 'B');
    return 0;
}
/* Output:
 Move disk 1 from rod A to rod C
 Move disk 2 from rod A to rod B
 Move disk 1 from rod C to rod B
 Move disk 3 from rod A to rod C
 Move disk 1 from rod B to rod A
 Move disk 2 from rod B to rod C
 Move disk 1 from rod A to rod C*/