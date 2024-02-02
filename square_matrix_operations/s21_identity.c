#include "../s21_matrix.h"

int s21_identity(matrix_t *result){

    if (!is_square_matrix(result))
        return FAILURE;

    for (int i = 0; i < result->rows; ++i) {
        for (int j = 0; j < result->columns; ++j) {
            if (i == j)
                result->matrix[i][j] = 1;
            else
                result->matrix[i][j] = 0;
        }
    }

    return SUCCESS;
}