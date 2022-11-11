#include <mpi.h>
#include <stdio.h>
int main()
{
  int rank, size;
  int tag, destination, count;
  int buffer;
  tag = 1234;
  destination = 1;
  count = 1;
  MPI_Status status;
  MPI_Request request = MPI_REQUEST_NULL;
  MPI_Init(NULL, NULL);
  int worldRank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  int worldSize;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  if (rank == 0)
  {
    buffer = 9999;
    double f1, f2;
    f1 = MPI_Wtime();
    MPI_Isend(&buffer, count, MPI_INT, destination, tag, MPI_COMM_WORLD, &request);
    f2 = MPI_Wtime();
    printf("Time diff between send: %1.2f\n", (f2 - f1));
  }
  if (rank == destination)
  {
    double f1, f2;
    f1 = MPI_Wtime();
    MPI_Irecv(&buffer, count, MPI_INT, 0, tag, MPI_COMM_WORLD, &request);
    f2 = MPI_Wtime();
    printf("Time diff between recv: %1.2f\n", (f2 - f1));
  }
  MPI_Wait(&request, &status);
  if (rank == 0)
  {
    printf("processor %d sent %d\n", worldRank, buffer);
  }
  if (rank == destination)
  {
    printf("processor %d rcv %d\n", worldRank, buffer);
  }
  MPI_Finalize();
  return 0;
}