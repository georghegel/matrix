#include "../s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
    if (does_matrix_exist(A)) {
        for (int j = A->columns; j > 0; --j)
            free(A[j]);
        free(A);
    }
}



