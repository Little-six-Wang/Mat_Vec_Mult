#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>
#include<math.h>
#include"parameters.h"

void Read_vector(double*, int, int, int, char*, int, MPI_Comm);
void Print_vector(double*, int, int, char*, int, MPI_Comm);
void get_input(int, int*, int*);
void Mat_vect_mult(double*, double*, double*, int local_m, int n, int local_n, MPI_Comm);

int main(){
  int my_rank, comm_sz;
  int n, m;
  int local_n, local_m;
  double* local_y = NULL, *local_x = NULL, *local_A = NULL;
  double local_start, local_final, local_elapsed;
  double elapsed;

  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  //get_input(my_rank, &m, &n);
  m = M;
  n = N;
  local_n = n / comm_sz;
  local_m = m / comm_sz;
	
  local_x = malloc(local_n * sizeof(double));
  local_y = malloc(local_m * sizeof(double));
  local_A = malloc(local_m * n * sizeof(double));

  Read_vector(local_A, n * local_m, m, n, "A", my_rank, MPI_COMM_WORLD);
  Read_vector(local_x, local_n, n, 1, "x", my_rank, MPI_COMM_WORLD);
	
  MPI_Barrier(MPI_COMM_WORLD);
  local_start = MPI_Wtime();
  Mat_vect_mult(local_A, local_x, local_y, local_m, n, local_n, MPI_COMM_WORLD);
  local_final = MPI_Wtime();
  local_elapsed = local_final - local_start;
  Print_vector(local_y, local_m, m, "the vector of y:", my_rank, MPI_COMM_WORLD);
  MPI_Reduce(&local_elapsed, &elapsed, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
  if(my_rank == 0){
    printf("sec = %lf\n", elapsed);
  }
  MPI_Finalize();
  return 0;
}
