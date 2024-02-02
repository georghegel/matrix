#include "../s21_matrix.h"

int is_square_matrix(matrix_t *matrix){
    return (matrix->columns == matrix->rows) ? SUCCESS : FAILURE;
}