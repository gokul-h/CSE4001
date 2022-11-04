#include <stdio.h>
#include <omp.h>
int main()
{
  omp_set_num_threads(4);
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int b[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int c[10];
  #pragma omp parallel for schedule(static, 3)
  for (int i = 0; i < 10; i++)
  {
    c[i] = a[i] + b[i];
    printf("C[%d] = %d thread ID %d\n", i, c[i], omp_get_thread_num());
  }
  return 0;
}