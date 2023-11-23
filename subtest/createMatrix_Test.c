#include<stdlib.h>

void createMatrix(int m, int n, double* a){
  double drand48();
  int i, j;
  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){
      a[i * n + j] = 2.0 * drand48() - 1;
    }
  }
}
