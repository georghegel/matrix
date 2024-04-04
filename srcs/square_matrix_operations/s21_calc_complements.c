#include "../../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int answer = OK;
  double determinant = 0.0;
  matrix_t inverse;
  matrix_t comps;

  if (A == NULL || result == NULL || !check_rows_columns(A->rows, A->columns)) {
    answer = INCORRECT_MATRIX;
  } else {
    s21_determinant(A, &determinant);

    if (determinant == 0.0 || determinant == -0.0 || !is_square_matrix(A)) {
      answer = CALCULATION_ERROR;
    } else {
      s21_inverse_matrix(A, &inverse);
      s21_mult_number(&inverse, determinant, &comps);
      s21_transpose(&comps, result);
      s21_remove_matrix(&inverse);
      s21_remove_matrix(&comps);
      answer = OK;
    }
  }
  return answer;
}