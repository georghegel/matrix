#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
    int answer = OK;

    if (!is_square_matrix(A) || is_determinant_zero(A))
        return INCORRECT_MATRIX;
    *result = 1.0;

    matrix_t row_echelon;
    s21_create_matrix(A->rows, A->columns, &row_echelon);

    gauss_elimination(A, &row_echelon, 0);

    for (int i = 0; i < A->rows; ++i)
        *result *= row_echelon.matrix[i][i];

    s21_remove_matrix(&row_echelon);

    return answer;
}