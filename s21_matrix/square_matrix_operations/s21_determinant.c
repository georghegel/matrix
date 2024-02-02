#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
    return gauss_elimination(A, result);
}