#include <stdio.h>
#include <omp.h>
#define N 10
int main()
{
    int a[N], d[N];
    int b[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int c[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    omp_set_num_threads(4);
#pragma omp for nowait
    for (int i = 0; i < N; i++)
    {
        a[i] = b[i] + c[i];
    }
#pragma omp parallel for shared(d)
    for (int i = 0; i < N; i++)
    {
        d[i] = a[i] + b[i];
        printf("%d\n", d[i]);
    }
    return 0;
}