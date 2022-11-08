# PDC

## List of experiments

| Lab | file_name                   | Description                                                                     |
| --- | --------------------------- | ------------------------------------------------------------------------------- |
| 1   | name.cpp                    | Print name multiple times using parallel                                        |
| 1   | sum_array.cpp               | Sum of two arrays using parallel                                                |
| -   | -                           | -                                                                               |
| 2   | sum_array_for.cpp           | Array Addition using Parallel For                                               |
| 2   | sample_pvt.cpp              | Sample for Private Variable                                                     |
| 2   | sum_array_for_pvt.cpp       | Array addition using parallel for with a, b, c as private arrays                |
| 2   | add_sub_parallel.cpp        | Parallelize addition and subtraction of two integer variables a and b           |
| -   | -                           | -                                                                               |
| 3   | first_private.c             | Sample first private                                                            |
| 3   | last_private.c              | Sample last private                                                             |
| 3   | first_private_with_d.c      | Sample first private with modification to d variable                            |
| -   | -                           | -                                                                               |
| 4   | sample_for_reduction.c      | Sample for Reduction                                                            |
| 4   | section.c                   | Parallel : c = a+b; c= a-b                                                      |
| 4   | sections_array.c            | Parallel : c[i] = a [i]+b[i] ; c [i] =a[i]\*b[i] ; c[i]-b[i]                    |
| 4   | prime.c                     | Implement listing of prime numbers < N                                          |
| 4   | sudoku.c                    | Implement "Sudoku solving algorithm (2\*2) (16 cells)                           |
| -   | -                           | -                                                                               |
| -   | -                           | -                                                                               |
| 6   | critical_without_parallel.c | Critical without parallel                                                       |
| -   | static.c                    | Static Schedule                                                                 |
| -   | dynamic.c                   | Dynamic schedule-                                                               |
| -   | wtime.c                     | wtime()-                                                                        |
| -   | directive.c                 | SET NUM OF THREADS USING DIRECTIVE CLAUSE                                       |
| -   | function.c                  | SET THREADS USING FUNCTION                                                      |
| -   | -                           | -                                                                               |
| 7   | barrier.c                   | -                                                                               |
| -   | no_wait.c                   | -                                                                               |
| -   | loop.c                      | -                                                                               |
| -   | loop2.c                     | -                                                                               |
| -   | -                           | -                                                                               |
| 8   | helloworld.c                | Sample Hello World                                                              |
| -   | rank.c                      | Prink rank, world size and processor name                                       |
| -   | master.c                    | Master prints "I am Master", Worker prints "I am worker"                        |
| -   | gp.c                        | Master generates 1/2,1/4,1/8,1/16...1/n; Worker generates 2,4,8,16...n          |
| -   | -                           | -                                                                               |
| 9   | -                           | Circuit Satisfiability                                                          |
| -   | -                           | Number of solutions in circuit satisfiability                                   |
| -   | -                           | Addig a count to all values of a matrix with size n\*n                          |
| -   | -                           | Find Max of 'n' no's                                                            |
| -   | -                           | Four Queen's Problem                                                            |
| -   | -                           | Sample isend, ireceive with mpi_wtime                                           |
| -   | -                           | Sample send and receive with mpi_wtime                                          |
| -   | -                           | Implementing the broadcast using send and receive                               |
| -   | -                           | Ring communication                                                              |
| -   | -                           | rank0 - sends randnum, rank1 - Add const , rank2 - sub const, rank3 - mul const |
| -   | -                           | Simulate a chat window - server answers query to client                         |
| -   | -                           | -                                                                               |
| -   | -                           | -                                                                               |
| -   | -                           | -                                                                               |

Procedure for MPI
mpicc hola.c -o hola

Then i run my program:

mpirun -np 5 ./hola
