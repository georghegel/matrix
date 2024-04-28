#include "../../matrix.h"

int is_equal_size(matrix_t *m1, matrix_t *m2) {
  return ((m1->rows == m2->rows) && (m1->columns == m2->columns));
}