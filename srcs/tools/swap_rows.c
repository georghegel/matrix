#include "../../matrix.h"

void swap_rows(int row_1, int row_2, matrix_t* matrix) {
  double* tmp = (double*)calloc(matrix->columns, sizeof(double));

  row_copy(tmp, matrix->matrix[row_1], matrix->columns);
  row_copy(matrix->matrix[row_1], matrix->matrix[row_2], matrix->columns);
  row_copy(matrix->matrix[row_2], tmp, matrix->columns);

  free(tmp);
}