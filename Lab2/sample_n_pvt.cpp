#include<stdio.h>
#include<omp.h>
int main(){
    int val;
	#pragma omp parallel 
	{
        val = omp_get_thread_num();
        printf("I am from thread - %d\n",val);
    }
    printf("\n");
	return 0;
}