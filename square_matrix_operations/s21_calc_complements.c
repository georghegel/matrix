#include "../s21_matrix.h"



matrix_t *s21_calc_minors(const matrix_t *matrix, int row, int column) {

    matrix_t *result;
    s21_create_matrix(matrix->rows, matrix->columns, result);

    for (int i = 0; i < matrix->rows - 1; ++i) {
        for (int j = 0; j < matrix->columns - 1; ++j) {
            if (i != row || column != j)
                result->matrix[i][j] = matrix->matrix[i][j];
        }
    }

    return result;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {

    matrix_t *minor_matrix;
    int rows = A->rows;
    int columns = A->columns;
    int sign = 0;
    double *det = 0;
    s21_create_matrix(rows, columns, result);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j)
            result->matrix[i][j] = 0;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            minor_matrix = s21_calc_minors(A, i, j);
            sign = ((i + j) % 2 == 0) ? -1 : 1;
            result->matrix[i][j] = ((-1) * sign) * s21_determinant(minor_matrix, det);
        }
    }

    return SUCCESS;
}