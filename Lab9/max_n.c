#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main()
{
  MPI_Init(NULL, NULL);
  int worldRank;
  MPI_Comm_rank(MPI_COMM_WORLD, &worldRank);
  int worldSize;
  MPI_Comm_size(MPI_COMM_WORLD, &worldSize);
  int lmax = -1;
  int array[5] = {10, 100, 1, 3, 4};

  for (int i = worldRank; i < 5; i += worldSize)
  {
    if (array[i] > lmax)
    {
      lmax = array[i];
    }
  }
  int max = -1;
  MPI_Reduce(&lmax, &max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

  if (worldRank == 0)
  {
    printf("Maximum of all numbers: %d\n", max);
  }
  MPI_Finalize();
}