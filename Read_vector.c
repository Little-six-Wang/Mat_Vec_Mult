#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>

void createMatrix(int, int, double*);

void Read_vector(double local_a[], int local_n, int m, int n,
                char vec_name[], int my_rank, MPI_Comm comm){
        double*a = NULL;
	int i;
	if(my_rank == 0){
		a = malloc(n * m *(sizeof(double)));
		createMatrix(m, n, a);
		MPI_Scatter(a, local_n, MPI_DOUBLE, local_a, local_n, MPI_DOUBLE, 0, comm);
		free(a);
	}else{
		MPI_Scatter(a, local_n, MPI_DOUBLE, local_a, local_n, MPI_DOUBLE, 0, comm);
	}
}
