#include "../s21_matrix.h"

void swap_rows(int row_1, int row_2, matrix_t *matrix) {

    double* tmp = malloc(sizeof(matrix->columns));

    row_copy(tmp, matrix->matrix[row_1], matrix->columns);
    row_copy(matrix->matrix[row_1], matrix->matrix[row_2], matrix->columns);
    row_copy(matrix->matrix[row_2], tmp, matrix->columns);

    free(tmp);
}