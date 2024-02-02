#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {

    if (A->columns != B->rows || \
        A->rows != result->rows || \
        A->columns != result->columns)
        return FAILURE;

    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < B->columns; ++j) {
            for (int k = 0; k < A->columns; ++k)
                result->matrix[i][j] = A->matrix[i][k] * B->matrix[k][j];
        }
    }
    return SUCCESS;
}