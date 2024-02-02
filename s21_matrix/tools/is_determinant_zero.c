#include "../s21_matrix.h"

int is_determinant_zero(matrix_t *matrix) {
    int row_cnt = count_zero_rc(matrix, matrix->rows, matrix->columns);
    int col_cnt = count_zero_rc(matrix, matrix->columns, matrix->rows);

    if (row_cnt != matrix->rows || col_cnt != matrix->columns)
        return FAILURE;

    return SUCCESS;
}

int count_zero_rc(matrix_t *matrix, int rows, int columns) {
    int res = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (matrix->matrix[i][j] != 0) {
                res = 0;
                break;
            }
            else
                res += 1;
        }
    }
    return res;
}

//int equal_rows_columns(matrix_t *matrix, int rows, int columns){
//
//    int res = 0;
//
//    for (int i = 0; i < rows; ++i) {
//        double row_1 = ;
//        for (int j = 0; j < columns; ++j) {
//
//        }
//    }
//
//
//    return res;
//}