#include "../s21_matrix.h"

void cayley_hamilton(matrix_t *matrix, matrix_t *result);
void matrix_pow(matrix_t *matrix, matrix_t *result, int exponent);

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {

    s21_create_matrix(A->rows, A->columns, result);

    double *det = 0;
    s21_determinant(A, det);

    result->matrix = (1 / det) * cayley_hamilton(A, result);


    return SUCCESS;
}

void cayley_hamilton(matrix_t *matrix, matrix_t *result) {

    int sign = 1;
    int n = matrix->columns;

    matrix_t *powered_matrix;
    s21_create_matrix(matrix->rows, matrix->columns, powered_matrix);

    matrix_t *sum;
    s21_create_matrix(matrix->rows, matrix->columns, sum);
    //zero matrix

    for (int k = 0; k < matrix->columns - 1; ++k) {
        sign = (n + k - 1 % 2) != 0 ? -1 : 1;

        matrix_pow(matrix, powered_matrix, n - k - 1);
        unsigned long long k_factorial= factorial(k);
        long long double bell_value = bell_polynomial();

        sum = sign * (powered_matrix / k_factorial) * bell_value;
        s21_sum_matrix(result, sum);
    }

}

void matrix_pow(matrix_t *matrix, matrix_t *result, int exponent) {

}