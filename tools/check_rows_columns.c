#include "../s21_matrix.h"

int check_rows_columns(int rows, int columns) {
  return rows < 1 || columns < 1 ? FAILURE : SUCCESS;
}