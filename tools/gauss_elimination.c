#include "../s21_matrix.h"

/*
 * There are several ways to calculate determinant of a square matrix.
 *
 * First way is intuitive and brute-force or Laplace's method: recursive way using adjugate matrix and minors.
 * Computational efficiency of this algorithm is O(n!) - which is insanely bad.
 *
 * Second way is from Linear Algebra: Gaussian Elimination to get row-echelon form.
 * When we get this form of a matrix, calculation of determinant becomes easy. Just multiply diagonal elements.
 * Computational efficiency - O(n^3 + n), thus O(n^3) - which is MUCH better, than the recursive way.
 *
 * References:
 * [1] Gauss Elimination - https://en.wikipedia.org/wiki/Gaussian_elimination
 * [2] Determinant - https://en.wikipedia.org/wiki/Determinant
 * [3] Computational Efficiency - https://en.wikipedia.org/wiki/Gaussian_elimination#Computational_efficiency
 * */

void elimination_processor(double *ratio, matrix_t *row_echelon, int i, int j, int dimension, int inverse){

    dimension = inverse ? dimension * 2 : dimension;

    *ratio = row_echelon->matrix[j][i] / row_echelon->matrix[i][i];
    for (int k = 0; k < dimension; ++k) {
        row_echelon->matrix[j][k] = row_echelon->matrix[j][k] - *ratio * row_echelon->matrix[i][k];
    }

}

void gauss_elimination(matrix_t *A, matrix_t *row_echelon, int for_inverse){

    int dimension = A->rows;

    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j)
            row_echelon->matrix[i][j] = A->matrix[i][j];
    }

    double ratio = 0.0;

    int first_zero_occur = 0;
    for (int i = 0; i < dimension; ++i) {
        if (row_echelon->matrix[i][i] == 0.0) {
            first_zero_occur = i;
            int non_zero_diag_element = find_non_zero_diagonal_element(i + 1, row_echelon);
            if (row_echelon->matrix[non_zero_diag_element][non_zero_diag_element] != 0.0) {
                swap_rows(first_zero_occur, non_zero_diag_element, row_echelon);
                for (int index = 0; index < dimension; ++index) row_echelon->matrix[i][index] *= -1;
            } else
                continue;
        } else
        {
            for (int j = 0; j < dimension; ++j) {
                if (for_inverse && i != j)
                    elimination_processor(&ratio, row_echelon, i, j, dimension, 1);
                else if (j > i)
                    elimination_processor(&ratio, row_echelon, i, j, dimension, 0);
            }
        }
    }
}