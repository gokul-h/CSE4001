#include<stdio.h>
#include<mpi.h>
int main(){
    MPI_Init(NULL,NULL);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD,&world_size);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD,&world_rank);
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name,&name_len);

    if(world_rank==0){
        printf("I am master\n");
    }
    else{ 
        printf("I am worker\n");
    }
    MPI_Finalize();
}