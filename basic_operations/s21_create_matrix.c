#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {

    if (check_rows_columns(rows, columns) && does_matrix_exist(result)) {
        result->matrix = malloc(sizeof(int**) * rows);
        if (!result->matrix)
            return FAILURE;
        for (int i = 0; i < rows; ++i) {
            result->matrix[i] = calloc(sizeof(int *) * columns, columns);
            if (!result->matrix[i]) {
                free(result->matrix);
                return FAILURE;
            }
        }
        result->rows = rows;
        result->columns = columns;
        return SUCCESS;
    } else
        return FAILURE;
}
