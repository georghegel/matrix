#include "../s21_matrix.h"

void create_augment_matrix(matrix_t *A, matrix_t *augment_matrix) {
    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns * 2; ++j) {
            if (j < A->columns)
                augment_matrix->matrix[i][j] = A->matrix[i][j];
            else {
                if (i == (j - A->columns))
                    augment_matrix->matrix[i][j] = 1;
                else
                    augment_matrix->matrix[i][j] = 0;
            }
        }
    }
}

void inverse_augment_matrix(matrix_t *A, matrix_t *augment_matrix){
    for (int i = 0; i < A->rows; ++i) {
        for (int j = A->rows; j < A->columns * 2; ++j) {
            augment_matrix->matrix[i][j] = augment_matrix->matrix[i][j] / augment_matrix->matrix[i][i];
        }
    }
}

// FIX IT
void copy_result(matrix_t *augment_matrix, matrix_t *result) {
    int k = 0;
    for (int i = 0; i < augment_matrix->rows; ++i) {
        for (int j = augment_matrix->rows; j < augment_matrix->columns; ++j) {
            result->matrix[i][k] = augment_matrix->matrix[i][j];
            ++k;
        }
        k = 0;
    }
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {

    double det = 0.0;
    s21_determinant(A, &det);

    matrix_t augment_matrix;
    s21_create_matrix(A->rows, A->columns, result);
    s21_create_matrix(A->rows, A->columns * 2, &augment_matrix);
    create_augment_matrix(A, &augment_matrix);
    gauss_elimination(A, &augment_matrix, 1);
    inverse_augment_matrix(A, &augment_matrix);
    copy_result(&augment_matrix, result);

    return SUCCESS;
}

