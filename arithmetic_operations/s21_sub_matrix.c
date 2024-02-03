#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int answer = OK;
    if (!does_matrix_exist(A) || \
        !does_matrix_exist(B))
        answer = INCORRECT_MATRIX;
    else if (!is_equal_size(A, B))
        answer = CALCULATION_ERROR;
    else {
        s21_create_matrix(A->rows, A->columns, result);
        for (int i = 0; i < A->rows; ++i) {
            for (int j = 0; j < A->columns; ++j)
                result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
    }
    return answer;
}