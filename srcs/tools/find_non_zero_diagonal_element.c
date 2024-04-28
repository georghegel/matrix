#include "../../matrix.h"

int find_non_zero_diagonal_element(int start, matrix_t *matrix) {
  int answer = start - 1;
  for (int i = start; i < matrix->rows && answer == start - 1; ++i) {
    if (matrix->matrix[i][i] != 0.0) answer = i;
  }
  return answer;
}
