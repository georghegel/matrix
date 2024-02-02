#include "../s21_matrix.h"

void swap_rows(int row_1, int row_2, matrix_t *matrix) {

    double* tmp = malloc(sizeof(matrix->columns));

    row_copy(tmp, matrix->matrix[row_1], matrix->columns);
    row_copy(matrix->matrix[row_1], matrix->matrix[row_2], matrix->columns);
    row_copy(matrix->matrix[row_2], tmp, matrix->columns);

    {
//    for (int i = 0; i < matrix->columns; ++i)
//        tmp[i] = matrix->matrix[row_1][i];
//
//    for (int i = 0; i < matrix->columns; ++i)
//        matrix->matrix[row_1][i] = matrix->matrix[row_2][i];
//
//    for (int i = 0; i < matrix->columns; ++i)
//        matrix->matrix[row_2][i] = tmp[i];
    }

    free(tmp);
}