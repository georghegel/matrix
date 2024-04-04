#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int answer = OK;
  matrix_t row_echelon;

  if (A == NULL || result == NULL || !check_rows_columns(A->rows, A->columns)) {
    answer = INCORRECT_MATRIX;
  } else {
    s21_create_matrix(A->rows, A->columns, &row_echelon);
    *result = 1.0;
    if (!is_square_matrix(A) || !does_matrix_exist(A)) {
      answer = CALCULATION_ERROR;
    } else {
      gauss_elimination(A, &row_echelon, NOT_INVERSE);
      for (int i = 0; i < A->rows; ++i) {
        *result *= row_echelon.matrix[i][i];
      }
      answer = OK;
    }
    s21_remove_matrix(&row_echelon);
  }
  return answer;
}