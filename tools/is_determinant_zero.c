#include "../s21_matrix.h"

int is_determinant_zero(matrix_t *matrix) {
    int row_cnt = count_zero_rows(matrix, matrix->rows, matrix->columns);
    int col_cnt = count_zero_columns(matrix, matrix->rows, matrix->columns);

    if (row_cnt == matrix->rows || col_cnt == matrix->columns)
        return INCORRECT_MATRIX;

    return OK;
}

int count_zero_rows(matrix_t *matrix, int rows, int columns) {
    int res = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (matrix->matrix[i][j] != 0.0) {
                res = 0;
                break;
            }
            else
                res += 1;
        }
    }
    return res;
}

int count_zero_columns(matrix_t *matrix, int rows, int columns) {
    int res = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (matrix->matrix[j][i] != 0) {
                res = 0;
                break;
            }
            else
                res += 1;
        }
    }
    return res;
}