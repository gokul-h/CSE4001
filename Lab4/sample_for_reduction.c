#include <stdio.h>
#include <omp.h>
int main()
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 2, 3, 4, 5};
    int arr3[5] = {0};
    int sum = 0;
    #pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < 5; i++)
    {
        arr3[i] = arr1[i] + arr2[i];
        sum = arr3[i];
        printf("Thread ID:-%d sum-%d \n",omp_get_thread_num(),sum);
    }

    printf("The sum is %d\n",sum);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr3[i]);
    }
    return 0;
}