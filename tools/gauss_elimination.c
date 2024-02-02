#include "../s21_matrix.h"

/*
 * There are several ways to calculate determinant of a square matrix.
 *
 * First way is intuitive and brute-force: recursive way using minors:
 * Computational efficiency of this algorithm is O(n!) - which is insanely bad.
 *
 * Second way is a mathematical approach: Gaussian Elimination to get row-echelon form.
 * When we get this form of a matrix calculation of a det becomes kid's stuff. Multiply diagonal.
 * Comp efficiency - O(n^3 + n), thus O(n^3) - which is A MUCH better, than factorial.
 *
 * References:
 * [1] Gauss Elimination - https://en.wikipedia.org/wiki/Gaussian_elimination
 * [2] Determinant - https://en.wikipedia.org/wiki/Determinant
 * [3] Computational Efficiency - https://en.wikipedia.org/wiki/Gaussian_elimination#Computational_efficiency
 * */

int gauss_elimination(matrix_t *A, double *result){

    if (is_determinant_zero(A))
        result = 0.0;
    else {
        int row_pivot = 0; /* Initialization of the pivot row */
        int column_pivot = 0; /* Initialization of the pivot column */

        int i_max = 0;
        int i = row_pivot;
        double f = 0;
        while (row_pivot < A->rows && column_pivot < A->columns) {
            i_max = argmax(i, column_pivot, A);
            if (A->matrix[i_max][column_pivot])
                ++column_pivot;
            else {
                swap_rows(row_pivot, i_max, A);
                for (i = h + 1; i < A->rows; ++i) {
                    f = A->matrix[i][column_pivot] / A->matrix[row_pivot][column_pivot];
                    A->matrix[i][column_pivot] = 0;
                    for (int j = column_pivot + 1; j < column_pivot; ++j)
                        A->matrix[i][j] = A->matrix[i][j] - A->matrix[row_pivot][j] * f;
                }
                ++row_pivot;
                ++column_pivot;
            }
        }

        result = 1.0;
        for (int i = 0; i < A->rows; ++i) {
            result *= A->matrix[i][i];
        }
    }
    return SUCCESS;
}