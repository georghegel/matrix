#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int answer = SUCCESS;
    if (!does_matrix_exist(A) || !does_matrix_exist(B) || \
            !is_equal_size(A, B))
        answer = FAILURE;

    for (int i = 0; i < A->rows && answer != FAILURE; ++i) {
        for (int j = 0; j < A->columns && answer != FAILURE; ++j) {
            if (A->matrix[i][j] != B->matrix[i][j])
                answer = FAILURE;
        }
    }
    return answer;
}



