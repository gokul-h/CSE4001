#include <stdio.h>
#include <omp.h>
int main()
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 2, 3, 4, 5};
    int arr3[5] = {0};
    #pragma omp parallel sections private(arr3)
    {
        #pragma omp section
        {
            #pragma omp parallel for
            for (int i = 0; i < 5; i++)
            {
                arr3[i] = arr1[i] + arr2[i];
            }
            printf("The sum of two arrays is \n");
            for (int i = 0; i < 5; i++)
            {
                printf("%d ", arr3[i]);
            }
            printf("\n");
        }
        #pragma omp section
        {
            #pragma omp parallel for
            for (int i = 0; i < 5; i++)
            {
                arr3[i] = arr1[i] - arr2[i];
            }
            printf("The difference of two arrays is \n");
            for (int i = 0; i < 5; i++)
            {
                printf("%d ", arr3[i]);
            }
            printf("\n");
        }
        #pragma omp section
        {
            #pragma omp parallel for
            for (int i = 0; i < 5; i++)
            {
                arr3[i] = arr1[i] * arr2[i];
            }
            printf("The product of two arrays is \n");
            for (int i = 0; i < 5; i++)
            {
                printf("%d ", arr3[i]);
            }
            printf("\n");
        }
    }
    return 0;
}