#include "../s21_matrix.h"

/*
 * There are several ways to calculate determinant of a square matrix.
 *
 * First way is intuitive and brute-force: recursive way using minors:
 * Computational efficiency of this algorithm is O(n!) - which is insanely bad.
 *
 * Second way is a mathematical approach: Gaussian Elimination to get row-echelon form.
 * When we get this form of a matrix calculation of a det becomes kid's stuff. Multiply diagonal elements.
 * Computational efficiency - O(n^3 + n), thus O(n^3) - which is A MUCH better, than the recursive way.
 *
 * References:
 * [1] Gauss Elimination - https://en.wikipedia.org/wiki/Gaussian_elimination
 * [2] Determinant - https://en.wikipedia.org/wiki/Determinant
 * [3] Computational Efficiency - https://en.wikipedia.org/wiki/Gaussian_elimination#Computational_efficiency
 * */

void gauss_elimination(matrix_t *A, double *result){

    matrix_t tmp;
    int dimension = A->rows;
    s21_create_matrix(dimension, dimension, &tmp);
    tmp.matrix = A->matrix;
    double ratio = 0.0;

    int first_zero_occur = 0;
    for (int i = 0; i < dimension; ++i) {
        if (tmp.matrix[i][i] == 0.0) {
            first_zero_occur = i;
            int non_zero_index = find_non_zero_diagonal_element(i + 1, &tmp);
            if (tmp.matrix[non_zero_index][non_zero_index] != 0.0) {
                swap_rows(first_zero_occur, non_zero_index, &tmp);
                for (int index = 0; index < dimension; ++index) tmp.matrix[i][index] *= -1;
            } else
                continue;
        } else
        {
            for (int j = 0; j < dimension; ++j) {
                if (j > i) {
                    ratio = tmp.matrix[j][i] / tmp.matrix[i][i];
                    for (int k = 1; k < dimension; ++k) {
                        tmp.matrix[j][k] = tmp.matrix[j][k] - ratio * tmp.matrix[i][k];
                    }
                }
            }
        }
    }
    for (int i = 0; i < dimension; ++i)
        *result *= tmp.matrix[i][i];
    s21_remove_matrix(&tmp);
}