#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#define SUCCESS 1
#define FAILURE 0

#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);     // DONE
void s21_remove_matrix(matrix_t *A);                                // DONE
int s21_eq_matrix(matrix_t *A, matrix_t *B);                        // DONE

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);     // DONE // CREATE RESULT MATRIX EVERYWHERE BELOW //
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);     // DONE
int s21_mult_number(matrix_t *A, double number, matrix_t *result);  // DONE
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);    // DONE

int s21_transpose(matrix_t *A, matrix_t *result);                   // DONE

int s21_calc_complements(matrix_t *A, matrix_t *result);            //NOT DONE                  HERE
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// TOOLS
int is_equal_size(matrix_t *m1, matrix_t *m2);                      // DONE
int does_matrix_exist(matrix_t *matrix);                            // DONE
int is_square_matrix(matrix_t *matrix);                             // DONE
int check_rows_columns(int rows, int columns);                      // DONE

double argmax(int begin, int end, matrix_t *matrix);
void row_copy(double *term1, double *term2, int columns);
void swap_rows(int row_1, int row_2, matrix_t *matrix);
int count_zero_rc(matrix_t *matrix, int rows, int columns);

// SQUARE MATRIX OPERATIONS
int is_determinant_zero(matrix_t *matrix);
int gauss_elimination(matrix_t *A, double *result);
int s21_diagonal(matrix_t *result, int number);
int s21_identity(matrix_t *result);
int s21_symmetric(matrix_t *matrix);
int s21_orthogonal(matrix_t *matrix);
int s21_trace(matrix_t *matrix, int *trace);


#endif