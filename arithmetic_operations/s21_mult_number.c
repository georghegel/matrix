#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    int answer = OK;
    if ((!does_matrix_exist(A) || \
        !does_matrix_exist(result)))
        answer = INCORRECT_MATRIX;
    else if (!is_equal_size(A, result))
        answer = CALCULATION_ERROR;

    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j)
            result->matrix[i][j] = A->matrix[i][j] * number;
    }

    return answer;
}