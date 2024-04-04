#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int answer = OK;
  if (check_rows_columns(rows, columns) && result != NULL) {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    result->rows = rows;
    result->columns = columns;
    if (result->matrix == NULL) {
      answer = INCORRECT_MATRIX;
    } else {
      for (int i = 0; i < rows; ++i) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          for (int j = i; j >= 0; --j) free(result->matrix[j]);
          free(result->matrix);
        }
      }
      answer = OK;
    }
  } else
    answer = INCORRECT_MATRIX;
  return answer;
}
