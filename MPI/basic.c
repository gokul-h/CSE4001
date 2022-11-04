// Typical MPI Initialization
#include<stdio.h>
#include<mpi.h>
int main(int argc, char **argv){
    MPI_Init(&argc,&argv);
    int num_process;
    int rank;
    MPI_Comm_size(MPI_COMM_WORLD,&num_process);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    printf("Hi Process - %d out of %d\n",rank,num_process);
    MPI_Finalize();
    return 0;
}