#include "../../matrix.h"

void delete_matrix(matrix_t *A) {
  if (A != NULL && does_matrix_exist(A)) {
    for (int j = A->rows - 1; j >= 0; --j) free(A->matrix[j]);
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}
