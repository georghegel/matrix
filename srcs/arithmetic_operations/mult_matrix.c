#include "../../matrix.h"

void multiplier(matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < B->columns; ++j) {
      for (int k = 0; k < A->columns; ++k)
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
    }
  }
}

int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int answer = OK;
  if (A == NULL || B == NULL || result == NULL ||
      !check_rows_columns(A->rows, A->columns) ||
      !check_rows_columns(B->rows, B->columns)) {
    answer = INCORRECT_MATRIX;
  } else {
    answer = create_matrix(A->rows, B->columns, result);
    if (A->columns != B->rows)
      answer = CALCULATION_ERROR;
    else {
      multiplier(A, B, result);
    }
  }
  return answer;
}