#include<stdio.h>
#include<mpi.h>

void get_input(int my_rank, int* m_p, int* n_p){
	if(my_rank == 0){
		printf("Enter the m n:\n");
		scanf("%d %d", n_p, m_p);
	}

	MPI_Bcast(m_p, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(n_p, 1, MPI_INT, 0, MPI_COMM_WORLD);
}
