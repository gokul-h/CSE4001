#include<stdio.h>
#include<omp.h>
int main(){
    int val = 5;
	#pragma omp parallel private(val)
	{
        val = omp_get_thread_num();
        printf("I am from thread - %d\n",val);
    }
    printf("\n");
	return 0;
}