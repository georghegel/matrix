#include "../s21_matrix.h"

int s21_diagonal(matrix_t *result, int number){

    if (!is_square_matrix(result))
        return FAILURE;

    for (int i = 0; i < result->rows; ++i) {
        for (int j = 0; j < result->columns; ++j) {
            if (i == j)
                result->matrix[i][j] = number;
            else
                result->matrix[i][j] = 0;
        }
    }
    return SUCCESS;
}