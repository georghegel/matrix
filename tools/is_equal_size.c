#include "../s21_matrix.h"

int is_equal_size(matrix_t *m1, matrix_t *m2) {
    if ((m1->columns != m2->columns) || (m1->rows != m2->rows))
        return FAILURE;
    return SUCCESS;
}