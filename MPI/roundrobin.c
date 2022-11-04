// Round Robin
#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>
#include<time.h>
void round_robin(int rank,int num_process){
    long int rand_mine,rand_prev;
    int rank_next = (rank +1) % num_process;
    int rank_prev = rank==0? num_process-1: rank-1;
    MPI_Status status;
    srandom(time(NULL) + rank);
    rand_mine = random()/(RAND_MAX/100);
    printf("Process-%d Random value is %ld\n",rank,rand_mine);
    if(rank%2==0){
        printf("%d:Sending %ld to %d\n",rank,rand_mine,rank_next);
        MPI_Send((void *)&rand_mine,1,MPI_LONG,rank_next,1,MPI_COMM_WORLD);
        printf("%d:Receiving from %d\n",rank,rank_prev);
        MPI_Recv((void *)&rand_prev,1,MPI_LONG,rank_prev,1,MPI_COMM_WORLD,&status);
    }
    else{
        printf("%d:Receiving from %d\n",rank,rank_prev);
        MPI_Recv((void *)&rand_prev,1,MPI_LONG,rank_prev,1,MPI_COMM_WORLD,&status);
        printf("%d:Sending %ld to %d\n",rank,rand_mine,rank_next);
        MPI_Send((void *)&rand_mine,1,MPI_LONG,rank_next,1,MPI_COMM_WORLD);
    }
}
int main(int argc, char **argv){
    MPI_Init(&argc,&argv);
    int num_process;
    int rank;
    MPI_Comm_size(MPI_COMM_WORLD,&num_process);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    printf("Hi Process - %d out of %d\n",rank,num_process);
    round_robin(rank,num_process);
    printf("Goodbye from - %d\n",rank);
    MPI_Finalize();
return 0;
}

//Output
// sort --numeric-sort --stable output.txt