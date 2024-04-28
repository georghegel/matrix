#include "../../matrix.h"

int does_matrix_exist(matrix_t *matrix) {
  return (matrix->matrix == NULL) ? FAILURE : SUCCESS;
}