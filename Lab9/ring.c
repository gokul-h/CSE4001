#include <stdio.h>
#include <mpi.h>
int main()
{
  MPI_Init(NULL, NULL);
  int worldRank;
  MPI_Comm_rank(MPI_COMM_WORLD, &worldRank);
  int worldSize;
  MPI_Comm_size(MPI_COMM_WORLD, &worldSize);
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  int name_len;
  MPI_Get_processor_name(processor_name, &name_len);
  printf("Hello World from processor %s, rank %d out of %d processors\n", processor_name, worldRank, worldSize);
  int token;
  if (worldRank != 0){
    MPI_Recv(&token, 1, MPI_INT, worldRank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process %d received token %d from process %d\n", worldRank, token, worldRank - 1);
  }
  else{
    token = 1263;
    MPI_Send(&token, 1, MPI_INT, (worldRank + 1) % worldSize, 0, MPI_COMM_WORLD);
  }
  if (worldRank == 0){
    MPI_Recv(&token, 1, MPI_INT, worldSize - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process %d received token %d from process %d\n", worldRank, token, worldSize - 1);
  }
  MPI_Finalize();
}