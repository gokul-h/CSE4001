#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    int arr1[10]={0,1,2,3,4,5,6,7,8,9};
    int arr2[10]={0,1,2,3,4,5,6,7,8,9};
    int arr3[10]={0};

    int d = 5;
    int sum =0;
    #pragma omp parallel for reduction(+:sum)
    for(int i=0;i<10;i++){
        sum = arr1[i] + arr2[i];
        printf("Hi from thread %d\n",omp_get_thread_num());
    }

    printf("sum is %d\n",sum);
    for(int i=0;i<10;i++){
        printf("%d ",arr3[i]);
    }
    printf("\n");
    return 0;
}