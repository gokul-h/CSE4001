#include <stdio.h>
#include <mpi.h>
#include<math.h> 
int main()
{
    int n = 10;
    MPI_Init(NULL, NULL);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);
    if (world_rank == 0)
    {
        for (int i = 1; i < n; i++)
        {
            printf("Master - 1/%d\n", (int)(pow(2,i)));
        }
    }
    else
    {
        for (int i = 1; i < n; i++)
        {

            printf("Worker - %d\n", (int)(pow(2,i)));
        }
    }
    MPI_Finalize();
}