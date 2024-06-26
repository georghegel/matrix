#include "../../matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int answer = OK;
  if (result == NULL || A == NULL || !check_rows_columns(A->rows, A->columns)) {
    answer = INCORRECT_MATRIX;
  } else {
    create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < result->rows; ++i) {
      for (int j = 0; j < result->columns; ++j) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return answer;
}