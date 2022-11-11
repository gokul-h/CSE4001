#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

void printMat(int mat[][6])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      printf("%d", mat[i][j]);
    }
    printf("\n");
  }
}
int main()
{
  MPI_Init(NULL, NULL);
  int worldRank;
  MPI_Comm_rank(MPI_COMM_WORLD, &worldRank);
  int worldSize;
  MPI_Comm_size(MPI_COMM_WORLD, &worldSize);
  int constant = 10;
  int mat[3][6] = {{1, 2, 3, 4, 5, 6}, {7, 8, 9, 1, 2, 0}, {3, 4, 5, 6, 7, 8}};
  if (worldRank == 0)
  {
    printf("Original Matrix:\n");
    printMat(mat);
  }
  for (int col = worldRank; col < 6; col += worldSize)
  {
    for (int i = 0; i < 3; i++)
    {
      mat[i][col] += 10;
      printf("After addition of 10 to mat[%d][%d], mat[%d,%d] = %d\n", i, col, i, col, mat[i][col]);
    }
  }
  MPI_Finalize();
}