#include <omp.h>
#include <stdio.h>
int main()
{
    int a[5][5] = {{1, 2, 3, 4, 5}, {25, 16, 9, 4, 1}, {4, 16, 100, 36, 9}, {25, 36, 49, 81, 4}, {4, 16, 49, 64, 1}};
    double st = omp_get_wtime();
#pragma omp parallel for
    for (int i = 1; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = 20 * a[i - 1][j];
        }
    }
    double end = omp_get_wtime();
    printf("Time taken: %f\n", (end - st));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    return 1;
}