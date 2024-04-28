#include "../../matrix.h"

int complements(matrix_t *A, matrix_t *result) {
  int answer = OK;
  double determinant = 0.0;
  matrix_t inv;
  matrix_t comps;

  if (A == NULL || result == NULL || !check_rows_columns(A->rows, A->columns)) {
    answer = INCORRECT_MATRIX;
  } else {
    determinant_m(A, &determinant);

    if (determinant == 0.0 || determinant == -0.0 || !is_square_matrix(A)) {
      answer = CALCULATION_ERROR;
    } else {
      inverse(A, &inv);
      mult_number(&inv, determinant, &comps);
      transpose(&comps, result);
      delete_matrix(&inv);
      delete_matrix(&comps);
      answer = OK;
    }
  }
  return answer;
}