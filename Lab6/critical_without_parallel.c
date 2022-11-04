#include <stdio.h>
#include <omp.h>
int main()
{
  int sum = 50;
  int tid;
  omp_set_num_threads(4);
#pragma omp critical
  {
    tid = omp_get_thread_num();
    sum += 100;
    printf("Sum: %d thread ID: %d\n", sum, tid);
  }
  return 0;
}