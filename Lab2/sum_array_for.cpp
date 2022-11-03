#include<stdio.h>
#include<omp.h>
int main(){
	//Input
	printf("Program to find sum of two arrays\n");
	int size;
	printf("Enter size of the array\n");
	scanf("%d",&size);
	int arr1[size],arr2[size],arr3[size];
	printf("Enter first array\n");
	for(int i=0;i<size;i++)
		scanf("%d",&arr1[i]);
	printf("Enter second array\n");
	for(int i=0;i<size;i++)
		scanf("%d",&arr2[i]);
	
	#pragma omp parallel for
		for(int i=0;i<size;i++)
			arr3[i] = arr1[i]+arr2[i];
	
	//Output
	printf("Sum of two arrays\n");
	for(int i=0;i<size;i++)
		printf("%d ",arr3[i]);
	
	return 0;
}

