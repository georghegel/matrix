#include "../../s21_matrix.h"

void row_copy(double *term1, const double *term2, int columns) {
  for (int i = 0; i < columns; ++i) term1[i] = term2[i];
}