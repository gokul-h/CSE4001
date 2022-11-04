#include <stdio.h>
#include <omp.h>
int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int c[10];
    double start = omp_get_wtime();
#pragma omp parallel for
    for (int i = 0; i < 0; i++)
    {
        c[i] = a[i] + b[i];
    }
    printf("Time taken to execute:%f\n",omp_get_wtime()-start);
    return 0;
}