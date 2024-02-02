#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int answer = OK;
    if (check_rows_columns(rows, columns)) {
        result->matrix = (double**)calloc(rows, sizeof(double*));
        result->rows = rows;
        result->columns = columns;
        if (!result->matrix)
            answer = INCORRECT_MATRIX;
        for (int i = 0; i < rows; ++i) {
            result->matrix[i] = (double*)calloc(columns, sizeof(double));
            if (!result->matrix[i]) {
                for (int k = i; k >= 0; --k) free(result->matrix[k]);
                free(result->matrix);
                answer = INCORRECT_MATRIX;
            }
        }
        answer = OK;
    } else
        answer = INCORRECT_MATRIX;
    return answer;
}
