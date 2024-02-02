#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {

    if ((!does_matrix_exist(A) || \
        !does_matrix_exist(result)) && \
        is_equal_size(A, result))
        return FAILURE;

    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j)
            result->matrix[i][j] = A->matrix[i][j] * number;
    }

    return SUCCESS;
}