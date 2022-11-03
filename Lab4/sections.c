#include <stdio.h>
#include <omp.h>
int main()
{
    int a = 5, b = 10, c = 0;
    #pragma omp parallel sections private(c)
    {
        #pragma omp section
        {
            c = a + b;
            printf("%d + %d = %d\n", a, b, c);
        }
        #pragma omp section
        {
            c = a - b;
            printf("%d - %d = %d\n", a, b, c);
        }
    }
    return 0;
}