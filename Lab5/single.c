#include<omp.h>
#include<stdio.h>
int main(){
    int TID,sum=0,i;
    #pragma omp parallel shared(sum) private(TID)
    {
        TID = omp_get_thread_num();

        #pragma omp single
        {
            sum += TID;
            printf("TID=%d sum=%d\n",TID,sum);
        }
        
    }
    return 0;
}