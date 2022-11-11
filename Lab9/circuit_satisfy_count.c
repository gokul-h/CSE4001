#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

int giveRandom()
{
  time_t t1;
  srand((unsigned)time(&t1));
  int a = rand() % 2;
  return a;
}
void checkCircuitSat(int rank, int i, int *local)
{
  int boolVal = giveRandom();
  if (boolVal == 1)
  {
    printf("Process %d has found a satisfiable combination in the %dth values\n", rank, i);
  (*local)++;
  }
}
int main()
{
  MPI_Init(NULL, NULL);
  int worldRank;
  MPI_Comm_rank(MPI_COMM_WORLD, &worldRank);
  int worldSize;
  MPI_Comm_size(MPI_COMM_WORLD, &worldSize);
  int local = 0;
  for (int i = worldRank; i < 64; i += worldSize)
  {
    checkCircuitSat(worldRank, i, &local);
  }
  int global;
  MPI_Reduce(&local, &global, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  if (worldRank == 0)
  {
    printf("\nTotal Solutions: %d", global);
  }
  MPI_Finalize();
}