
# matrix
Matrix - is a library with basic operations, written on C. <br>
It allows to create, delete, add/subtract/multiply matrices. <br>
Also you can get determinant, inverse and algebraic complements in O(n^3) time complexity.

## Installation and usage
### MacOS
```shell
$ git clone https://github.com/georghegel/matrix.git
$ cd matrix
$ make
```
For testing:
```shell
$ make test
```

### Ubuntu
Pretty similar to macOS.<br>
*for now `make test` doesn't work correctly, and I'm fixing it*
```shell
$ git clone https://github.com/georghegel/matrix.git
$ cd matrix
$ make
```
For testing:
```shell
$ make test
```

### Windows
*not ready yet*
## Matrix creation, deletion, comparer
Create matrix (initial matrix will be filled with zeros):
```c
matrix_t my_matrix;
create_matrix(3, 3, &my_matrix);

my_matrix[0][0] = 7;
my_matrix[0][1] = 3;
my_matrix[0][2] = 4;

my_matrix[1][0] = 5;
my_matrix[1][1] = 2;
my_matrix[1][2] = 1;

my_matrix[2][0] = 9;
my_matrix[2][1] = 11;
my_matrix[2][2] = 17;
```

Delete matrix:
```c
delete_matrix(&my_matrix);
```
Next function returns 0 if element-wise comparison is successful (e.g. each corresponding element are equal). <br>
Otherwise 1 will return.
```c
matrix_t A, B;
create_matrix(3, 3, &A);
create_matrix(3, 3, &B);

// fill matrix A and B with your values as we did before

int res = eq_matrix(&A, &B);
```

## Basic operations on matrices

[Addition/subtraction](https://en.wikipedia.org/wiki/Matrix_addition#Entrywise_sum):
```c
matrix_t A, B, result;

create_matrix(3, 3, &A);
create_matrix(3, 3, &B);

sum_matrix(&A, &B, &result);
sub_matrix(&A, &B, &result); 
```

Scalar multiplication:

```c
double number = 2.73;

mult_number(&A, number, &result);
```

[Matrix multiplication:](https://en.wikipedia.org/wiki/Matrix_multiplication#Definition)
```c
matrix_t A, B, result;

create_matrix(3, 4, &A);
create_matrix(4, 5, &B);

mult_matrix(&A, &B, &result);
```

## Transpose
[Matrix transposition:](https://en.wikipedia.org/wiki/Transpose#Transpose_of_a_matrix)
```c
matrix_t A, result;

create_matrix(3, 7, &A);

transpose(&A, &result);
// result matrice's rows and cols = (7, 3);
```


## Determinant, inverse and algebraic complements matrix
[Determinant:(a bit difficult concept)](https://en.wikipedia.org/wiki/Determinant)
```c
double result = 0.0;
determinant_m(&A, &result);
```

[Inverse matrix:](https://en.wikipedia.org/wiki/Invertible_matrix)
```c
inverse(&A, &result);
```

[Algebraic complements matrix:](https://en.wikipedia.org/wiki/Minor_(linear_algebra)#Complement)<br>
To understand this concept you should be familiar with minors, which is obvious.
```c
complements(&A, &result);
```


## References:
[1] [Кострикин - Введение в Алгебру](https://studizba.com/files/show/pdf/65970-1-vvedenie-v-algebru--kostrikin--chast.html)<br>
[2] [Винберг - Курс алгебры](https://mathprofi.com/uploads/files/2581_f_41_e.b.vinberg-kurs-algebry-2-e-izd.pdf)<br>
[3] [Gauss elimination - wikipedia]()<br>
[4] [Invertible matrices - wikipedia](https://en.wikipedia.org/wiki/Invertible_matrix)
