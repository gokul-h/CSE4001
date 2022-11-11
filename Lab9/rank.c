#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>
int main()
{
  MPI_Init(NULL, NULL);
  int buffer;
  MPI_Status status;
  int worldRank;
  MPI_Comm_rank(MPI_COMM_WORLD, &worldRank);
  int worldSize;
  MPI_Comm_size(MPI_COMM_WORLD, &worldSize);
  if (worldRank == 0)
  {
    time_t t1;
    srand((unsigned)time(&t1));
    int a = rand() % 100 + 20;
    printf("Root Process sent value:- %d\n", a);
    for (int i = 0; i < worldSize; i++)
    {
      MPI_Send(&a, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
    }
  }
  else if (worldRank == 1)
  {
        MPI_Recv(&buffer,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        buffer+=10;
        printf("process %d Added constant to send data from root, current value: %d\n",worldRank,buffer);
  }
  else if (worldRank == 2)
  {
        MPI_Recv(&buffer,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        buffer-=10;
        printf("process %d Subtracted constant to send data from root, current value: %d\n",worldRank,buffer);
  }
  else
  {
        MPI_Recv(&buffer,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        buffer*=10;
        printf("process %d Multiplied constant to send data from root, current value: %d\n",worldRank,buffer);
  }
  MPI_Finalize();
  return 0;
}