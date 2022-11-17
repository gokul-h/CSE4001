#include <stdio.h>
#include <omp.h>
int main()
{
    int a = 5, b = 4, c;
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            printf("Thread ID:-%d\n",omp_get_thread_num());
            printf("%d - %d = %d\n\n", a, b, a - b);
        }
        #pragma omp section
        {
            printf("Thread ID:-%d\n",omp_get_thread_num());
            printf("%d + %d = %d\n", a, b, a + b);
        }
    }
    return 0;
}