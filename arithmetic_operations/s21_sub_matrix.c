#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {

    if ((!does_matrix_exist(A) || \
        !does_matrix_exist(B) || \
        !does_matrix_exist(result)) && !is_equal_size(A, B))
        return FAILURE;

    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j)
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }

    return SUCCESS;
}