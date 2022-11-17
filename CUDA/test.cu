int main(){
	int *a;
	cudaMalloc(&a,10);
	cudaFree(a);
	return 0;
}
