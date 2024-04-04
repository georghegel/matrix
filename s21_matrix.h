#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define EPS 1e-07

#define SUCCESS 1
#define FAILURE 0

#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

#define INVERSE 1
#define NOT_INVERSE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int is_determinant_zero(matrix_t *matrix);
void gauss_elimination(matrix_t *A, matrix_t *row_echelon, int for_inverse);
int find_non_zero_diagonal_element(int start, matrix_t *matrix);
// int s21_diagonal(matrix_t *matrix, int number);

int is_equal_size(matrix_t *m1, matrix_t *m2);
int does_matrix_exist(matrix_t *matrix);
int is_square_matrix(matrix_t *matrix);
int check_rows_columns(int rows, int columns);
void row_copy(double *term1, const double *term2, int columns);
void swap_rows(int row_1, int row_2, matrix_t *matrix);
int count_zero_rows(matrix_t *matrix, int rows, int columns);
int count_zero_columns(matrix_t *matrix, int rows, int columns);

#endif