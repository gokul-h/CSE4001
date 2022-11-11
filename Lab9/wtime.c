#include <stdio.h>
#include <mpi.h>
int main()
{
  MPI_Init(NULL, NULL);
  int worldRank;
  MPI_Comm_rank(MPI_COMM_WORLD, &worldRank);
  int worldSize;
  MPI_Comm_size(MPI_COMM_WORLD, &worldSize);
  if (worldRank == 0)
  {
    int data = 1263;
    double f1, f2;
    f1 = MPI_Wtime();
    MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    f2 = MPI_Wtime();
    printf("Time diff between send: %1.2f\n", (f2 - f1));
  }
  else if(worldRank == 1)
  {
    int buffer;
    double f1, f2;
    f1 = MPI_Wtime();
    MPI_Recv(&buffer, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    f2 = MPI_Wtime();
    printf("received data: %d\n", buffer);
    printf("Time diff between recv: %1.2f\n", (f2 - f1));
  }
  MPI_Finalize();
  return 0;
}