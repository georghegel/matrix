
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
create_matrix(3,3, &my_matrix);
```
Delete matrix:
```
delete_matrix(&my_matrix);
```
Comparer returns 0 if at least one element differ. <br>
Otherwise 1 return.
```
matrix_t A, B;
create_matrix(3,3, &A);
create_matrix(3,3, &B);

// fill matrix A and B with your values

if (eq_matrix(&A, &B)) {
    ...
}
```

## Basic operations on matrices

Addition/subtraction:
```
matrix_t A, B, result;

create_matrix(3,3, &A);
create_matrix(3,3, &B);

sum_matrix(&A, &B, &result);
sub_matrix(&A, &B, &result); 
```

Scalar multiplication:

```
double number = 2.73;
mult_number(&A, number, &result);
```

Matrix multiplication:

```
matrix_t A, B, result;

create_matrix(3, 4, &A);
create_matrix(4, 5, &B);

mult_number(&A, &B, &result);
```

## Transpose
```
transpose(&A, &result);
```


## Determinant, inverse and algebraic complements matrix
Determinant:
```
double result = 0.0;
determinant(&A, &result);
```

Inverse matrix:
```
inverse(&A, &result);
```

Algebraic complements matrix:
```
complements(&A, &result);
```


## Trace, diagonal matrices and other useful tools.
*on work*


## References:
[1] Кострикин - Введение в Алгебру<br>
[2] Винберг - Курс алгебры<br>
[3] Gauss elimination - wikipedia<br>
[4] Invertible matrices - wikipedia<br>
