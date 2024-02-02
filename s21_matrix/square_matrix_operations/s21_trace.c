#include "../s21_matrix.h"

int s21_trace(matrix_t *matrix, int *trace){

    trace = 0;
    if (!is_square_matrix(matrix))
        return FAILURE;

    for (int i = 0; i < matrix->rows; ++i) {
        for (int j = 0; j < matrix->columns; ++j) {
            if (i == j)
                trace += matrix->matrix[i][j];
        }
    }
    return SUCCESS;
}