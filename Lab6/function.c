#include <stdio.h>
#include <omp.h>
int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int c[10];
    omp_set_num_threads(4);
#pragma omp prallel for
    for (int i = 0; i < 0; i++)
    {
        c[i] = a[i] + b[i];
    }
    printf("Threads are set using omp_set_num_threads()\n");
    return 0;
}