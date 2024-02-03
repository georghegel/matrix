#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
    int answer = OK;

    if (!is_square_matrix(A) || is_determinant_zero(A))
        return INCORRECT_MATRIX;
    *result = 1.0;

    gauss_elimination(A, result);

    return answer;
}