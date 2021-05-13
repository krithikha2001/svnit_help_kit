#include<stdio.h>
#include<stdlib.h>
#include<time.h>

clock_t start, end;
double cpu_time_used;
int * * matrix_allocate(int n) {
  int i, j;
  int * * c = (int * * ) malloc(n * sizeof(int * ));
  for (i = 0; i < n; ++i) {
          c[i] = (int * ) malloc(n * sizeof(int));
  }
  return c;
}
void matrix_free(int ** m, int n) {
  int i;
  for (i = 0; i < n; i++) {
    free(m[i]);
  }
  free(m);
}
int ** matrix_add(int ** a, int ** b, int n) {
  int i, j;
  int ** c = matrix_allocate(n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
         c[i][j] = a[i][j] + b[i][j];
    }
  }
  return c;
}
int ** matrix_mul(int ** a, int ** b, int n) {
  int i, j;
  int ** c = matrix_allocate(n);
  if (n == 1) {
     c[0][0] = a[0][0] * b[0][0];
  } 
  else {
     int ** a11 = matrix_allocate(n / 2);
     int ** a12 = matrix_allocate(n / 2);
     int ** a21 = matrix_allocate(n / 2);
     int ** a22 = matrix_allocate(n / 2);
     int ** b11 = matrix_allocate(n / 2);
     int ** b12 = matrix_allocate(n / 2);
     int ** b21 = matrix_allocate(n / 2);
     int ** b22 = matrix_allocate(n / 2);
     for (i = 0; i < n / 2; i++) {
        for (j = 0; j < n / 2; j++) {
             a11[i][j] = a[i][j];
             a12[i][j] = a[i][j + n / 2];
             a21[i][j] = a[i + n / 2][j];
             a22[i][j] = a[i + n / 2][j + n / 2];
             b11[i][j] = b[i][j];
             b12[i][j] = b[i][j + n / 2];
             b21[i][j] = b[i + n / 2][j];
             b22[i][j] = b[i + n / 2][j + n / 2];
        }
     }
     int ** c11 = matrix_add(matrix_mul(a11, b11, n / 2), matrix_mul(a12, b21, n / 2), n / 2);
     int ** c12 = matrix_add(matrix_mul(a11, b12, n / 2), matrix_mul(a12, b22, n / 2), n / 2);
     int ** c21 = matrix_add(matrix_mul(a21, b11, n / 2), matrix_mul(a22, b21, n / 2), n / 2);
     int ** c22 = matrix_add(matrix_mul(a21, b12, n / 2), matrix_mul(a22, b22, n / 2), n / 2);
     for (i = 0; i < n / 2; i++) {
        for (j = 0; j < n / 2; j++) {
             c[i][j] = c11[i][j];
             c[i][j + n / 2] = c12[i][j];
             c[i + n / 2][j] = c21[i][j];
             c[i + n / 2][j + n / 2] = c22[i][j];
        }
     }
     matrix_free(c11, n / 2);
     matrix_free(c12, n / 2);
     matrix_free(c21, n / 2);
     matrix_free(c22, n / 2);
    }
    /*for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
         printf("%d\t",c[i][j]);
    }
    printf("\n");
  }*/
     return c;
}
int main() {
  clock_t start, end;
  double t;
  int i, j, k, m, n;
  printf("Enter number of rows=colums\n");
  scanf("%d", & n);
  int ** a = matrix_allocate(n);
  int ** b = matrix_allocate(n);
  printf("\nEnter elements of first matrix: ");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
         scanf("%d", & a[i][j]);
    }
  }
  printf("Enter elements of second matrix: ");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
         scanf("%d", & b[i][j]);
    }
  }
  start = clock();
  matrix_mul(a, b, n);
  end = clock();
  t = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Time Taken: %.9f", t);
  return 0;
}
