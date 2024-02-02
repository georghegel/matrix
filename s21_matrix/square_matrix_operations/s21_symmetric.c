#include "../s21_matrix.h"

int s21_symmetric(matrix_t *matrix){

    matrix_t *transposed;
    s21_create_matrix(matrix->rows, matrix->columns, transposed);

    if (!is_equal_size(matrix, transposed))
        return FAILURE;

    for (int i = 0; i < matrix->rows; ++i) {
        for (int j = 0; j < matrix->columns; ++j) {
            if (transposed->matrix[i][j] != matrix->matrix[i][j])
                return FAILURE;
        }
    }
    return SUCCESS;
}