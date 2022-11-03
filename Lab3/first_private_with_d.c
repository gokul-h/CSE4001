#include <stdio.h>
#include <omp.h>
int main()
{
	// Input
	int arr1[4] = {1, 2, 3, 4}, arr2[4] = {1, 2, 3, 4}, arr3[4] = {0};
	int d = 5;
	int max=0;

	#pragma omp parallel for firstprivate(d) lastprivate(max)
	for (int i = 0; i < 4; i++)
	{
		arr3[i] = arr1[i] + arr2[i] + d;
        // Modification to d
		d += i;
		max = arr3[i];
	}

	// Output
	printf("Sum of two arrays\n");
	for (int i = 0; i < 4; i++)
		printf("%d ", arr3[i]);
	printf("\n");
	printf("Max is %d\n",max);
	return 0;
}
