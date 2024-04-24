#include "../../s21_matrix.h"

void create_augment_matrix(matrix_t *A, matrix_t *augment_matrix) {
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns * 2; ++j) {
      if (j < A->columns)
        augment_matrix->matrix[i][j] = A->matrix[i][j];
      else {
        if (i == (j - A->columns))
          augment_matrix->matrix[i][j] = 1;
        else
          augment_matrix->matrix[i][j] = 0;
      }
    }
  }
}

void inverse_augment_matrix(matrix_t *A, matrix_t *augment_matrix) {
  for (int i = 0; i < A->rows; ++i) {
    for (int j = A->rows; j < A->columns * 2; ++j) {
      augment_matrix->matrix[i][j] =
          augment_matrix->matrix[i][j] / augment_matrix->matrix[i][i];
    }
  }
}

void copy_result(matrix_t *augment_matrix, matrix_t *result) {
  int k = 0;
  for (int i = 0; i < augment_matrix->rows; ++i) {
    for (int j = augment_matrix->rows; j < augment_matrix->columns; ++j) {
      result->matrix[i][k] = augment_matrix->matrix[i][j];
      ++k;
    }
    k = 0;
  }
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int answer = OK;
  matrix_t augment_matrix;
  double determinant = 0.0;

  if (A == NULL || result == NULL || !check_rows_columns(A->rows, A->columns)) {
    answer = INCORRECT_MATRIX;
  } else {
    s21_determinant(A, &determinant);
    if (determinant == 0.0 || determinant == -0.0 || !is_square_matrix(A)) {
      answer = CALCULATION_ERROR;
    } else {
      s21_create_matrix(A->rows, A->columns, result);
      s21_create_matrix(A->rows, A->columns * 2, &augment_matrix);
      create_augment_matrix(A, &augment_matrix);

      gauss_elimination(A, &augment_matrix, INVERSE);
      inverse_augment_matrix(A, &augment_matrix);
      copy_result(&augment_matrix, result);
      s21_remove_matrix(&augment_matrix);
      answer = OK;
    }
  }
  return answer;
}
