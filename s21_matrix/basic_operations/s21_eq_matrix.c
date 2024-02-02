#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {

    if (!does_matrix_exist(A) || !does_matrix_exist(B) || \
            !is_equal_size(A, B))
        return FAILURE;

    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; i < A->columns; ++j) {
            if (A->matrix[i][j] != B->matrix[i][j])
                return FAILURE;
        }
    }
    return SUCCESS;
}



