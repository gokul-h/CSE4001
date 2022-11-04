# MPI

Message passing communication
Cross Platform

MPICH implementation

## Communicatio n DOmain
Process that can communicate with each other
Stored in communicator
Communicator type: MPI_Comm
Default communicator: MPI_COMM_WORLD

First Line
int MPI_Init(int *argc,char ***argv)

Last Line
int MPI_Finalize();

Total processes
int MPI_Comm_size(MPI_Comm comm,int *size)

Local process index
int MPI_Comm_rank(MPI_Comm comm,int *rank)

Uses a lot of pointers
pass adress to mpi to fill values


### Primitive Communication
b/w processes
'''
int MPI_Send(void *buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm)

int MPI_Receive(void *buf,int count,MPI_Datatype datatype,int source,int tag,MPI_Comm commMPI_Status *status)
'''

### MPI Status value
'''
typedef struct MPI_Status {
    int MPI_SOURCE;
    int MPI_TAG;
    int MPI_ERROR;
}
'''

## MPI_Advanced
1. Simultaneous send and Receive - MPI_Sendrecv
2. Collective Communication
3. Non-Blocking Communication
4. Topologies

