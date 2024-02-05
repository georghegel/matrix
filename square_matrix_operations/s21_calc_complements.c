#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {

    s21_create_matrix(A->rows, A->columns, result);

    double det = 0.0;
    s21_determinant(A, &det);

    matrix_t inverse;
    matrix_t comps;

    s21_create_matrix(A->rows, A->columns, &inverse);
    s21_inverse_matrix(A, &inverse);
    s21_create_matrix(A->rows, A->columns, &comps);
    s21_mult_number(&inverse, det, &comps);
    s21_transpose(&comps, result);

    return SUCCESS;
}