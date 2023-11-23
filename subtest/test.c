#include<stdio.h>
#include<stdlib.h>
#include"parameters.h"

void createMatrix(int m, int n, double* a);
double dclock();

int main(){
  int n, m;
  double time_use;
  double* A = NULL;
  double* X = NULL;
  double* Y = NULL;
  m = M;
  n = N;
  A = malloc(m * n * sizeof(double));
  X = malloc(n * sizeof(double));
  Y = malloc(n * sizeof(double));
  createMatrix(m, n, A);
  createMatrix(1, n, X);
  int i, j;
  time_use = dclock();
  for(i = 0; i < m; i++){
    Y[i] = 0.0;
      for(j = 0; j < n; j++){
        Y[i] += A[i *  n + j] * X[j];
      }
  }
  time_use = dclock() - time_use;
  printf("Result=[\n");
  for(i = 0; i < n; i++){
    printf("%lf ", Y[i]);
  }
  printf("]\n");
  printf("sec = %lf", time_use);
  free(A);
  free(X);
  free(Y);
  return 0;
}
