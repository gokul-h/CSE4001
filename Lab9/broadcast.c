#include <stdio.h>
#include <mpi.h>
void my_bcast(int count, MPI_Datatype datatype, int root, MPI_Comm communicator)
{
  int worldRank;
  MPI_Comm_rank(MPI_COMM_WORLD, &worldRank);
  int worldSize;
  MPI_Comm_size(MPI_COMM_WORLD, &worldSize);
  if (worldRank == root){
    int data = 1263;
    printf("root process %d sent: %d \n", root, data);
    int i;
    for (int i = 0; i < worldSize; i++)
    {
      if (i != worldRank)
      {
        MPI_Send(&data, count, datatype, i, 0, communicator);
      }
    }
  }
  else{
    int data;
    MPI_Recv(&data, count, datatype, root, 0, communicator, MPI_STATUS_IGNORE);
    printf("process %d received:%d\n", worldRank, data);
  }
}
int main()
{
  MPI_Init(NULL, NULL);
  my_bcast(1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Finalize();
}