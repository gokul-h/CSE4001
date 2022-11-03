#include<stdio.h>
#include<omp.h>
int main(){
	int arr1[4] = {1, 2, 3, 4}, arr2[4] = {1, 2, 3, 4}, arr3[4] = {0};
	#pragma omp parallel for firstprivate(arr1,arr2,arr3)
		for(int i=0;i<4;i++)
			arr3[i] = arr1[i]+arr2[i];
	
	//Output
	printf("Sum of two arrays\n");
	for(int i=0;i<4;i++)
		printf("%d ",arr3[i]);
	printf("\n");
	return 0;
}

