
# matrix
Matrix - is a library with basic operations, written on C. <br>
It allows to create, delete, add/subtract/multiply matrices. <br>
Also you can get determinant, inverse and algebraic complements in O(n^3) time complexity.

## Installation and usage
### MacOS
```
$ git clone https://github.com/georghegel/matrix.git
$ cd matrix
$ make
```
For testing:
```
$ make test
```

### Ubuntu
Pretty similar to MacOS.<br>
*for now `make test` doesn't work correctly and I'm fixing it*
```
$ git clone https://github.com/georghegel/matrix.git
$ cd matrix
$ make
```
For testing:
```
$ make test
```

### Windows
*not ready yet*
## Matrix creation, deletion, comparer
Create matrix (initial matrix will be filled with zeros):
```
matrix_t my_matrix;
s21_create_matrix(3,3, &my_matrix);
```
Delete matrix:
```
s21_remove_matrix(&my_matrix);
```
Comparer returns 0 if at least one element differ. <br>
Otherwise 1 return.
```
matrix_t A, B;
s21_create_matrix(3,3, &A);
s21_create_matrix(3,3, &B);

// fill matrix A and B with your values

if (s21_eq_matrix(&A, &B)) {
    ...
}
```

## Basic operations on matrices

Addition/subtraction:
```
matrix_t A, B, result;

s21_create_matrix(3,3, &A);
s21_create_matrix(3,3, &B);

s21_sum_matrix(&A, &B, &result);
s21_sub_matrix(&A, &B, &result); 
```

Scalar multiplication:

```
double number = 2.73;
s21_mult_number(&A, number, &result);
```

Matrix multiplication:

```
matrix_t A, B, result;

s21_create_matrix(3, 4, &A);
s21_create_matrix(4, 5, &B);

s21_mult_number(&A, &B, &result);
```

## Transpose
```
s21_transpose(&A, &result);
```


## Determinant, inverse and algebraic complements matrix
Determinant:
```
double result = 0.0;
s21_determinant(&A, &result);
```

Inverse matrix:
```
s21_inverse_matrix(&A, &result);
```

Algebraic complements matrix:
```
s21_calc_complements(&A, &result);
```


## Trace, diagonal matrices and other useful tools.
*on work*


## References:
[1] Кострикин - Введение в Алгебру<br>
[2] Винберг - Курс алгебры<br>
[3] Gauss elimination - wikipedia<br>
[4] Invertible matrices - wikipedia<br>
