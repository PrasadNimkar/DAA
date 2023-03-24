// Practical 1
#include <stdio.h>
int toh(int n, char source, char aux, char destination)
{
  if (n == 1)
  {
    printf("Move %c to %c\n", source, destination);
    return 0;
  }
  else
    toh(n - 1, source, destination, aux);
  printf("Move %c to %c\n", source, destination);
  toh(n - 1, aux, source, destination);
}
int main()
{
  int n = 3;
  toh(n, 'A', 'B', 'C');
}
/*Output
Move A to C
Move A to B
Move C to B
Move A to C
Move B to A
Move B to C
Move A to C
*/