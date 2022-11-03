#include <stdio.h>
#include <omp.h>
int main()
{
  printf("Enter the number till which prime numbers has to be found - ");
  int n, is_prime = 1, total = 0;
  scanf("%d", &n);
  printf("prime numbers are:\n");
  #pragma omp parallel for reduction(+ : total)
  for (int i = 2; i < n; i++)
  {
    is_prime = 1;
    for (int j = 2; j < i; j++)
    {
      if (i % j == 0)
      {
        is_prime = 0;
        break;
      }
    }
    if (is_prime)
    {
      printf("%d ",i);
      total++;
    }
  }

  printf("\nTotal number of prime numbers under %d is %d\n", n, total);
}