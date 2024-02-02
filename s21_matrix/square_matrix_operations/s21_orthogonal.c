#include "../s21_matrix.h"

int s21_orthogonal(matrix_t *matrix) {

    if (!does_matrix_exist(matrix) || !is_square_matrix(matrix))
        return FAILURE;

    matrix_t *identity_matrix;
    matrix_t *transposed;
    matrix_t *result_1;
    matrix_t *result_2;

    s21_create_matrix(matrix->rows, matrix->columns, identity_matrix);
    s21_create_matrix(matrix->rows, matrix->columns, transposed);
    s21_create_matrix(matrix->rows, matrix->columns, result_1);
    s21_create_matrix(matrix->rows, matrix->columns, result_2);
    s21_transpose(matrix, transposed);

    s21_mult_matrix(transposed, matrix, result_1);
    s21_mult_matrix(transposed, matrix, result_2);

    if (!s21_eq_matrix(result_1, result_2) || \
        !s21_eq_matrix(result_1, identity_matrix) || \
        s21_eq_matrix(result_2, identity_matrix))
        return FAILURE;

    return SUCCESS;
}
