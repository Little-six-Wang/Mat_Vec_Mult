#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>

void Print_vector(double local_b[], int local_n, int n, char title[],
		int my_rank, MPI_Comm comm){
	double*b = NULL;
	int i;
	if(my_rank == 0){
		b = malloc(n * sizeof(double));
		MPI_Gather(local_b, local_n, MPI_DOUBLE, b, local_n,
				MPI_DOUBLE, 0, comm);
		printf("%s\n", title);
		for(i = 0; i < n; i++){
			printf("%lf ", b[i]);
		}
		printf("\n");
		free(b);
	}else{
		MPI_Gather(local_b, local_n, MPI_DOUBLE, b, local_n,
				MPI_DOUBLE, 0, comm);
	}
}
