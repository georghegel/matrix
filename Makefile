CC=gcc
FLAGS=-Wall -Wextra -Werror --std=c11

TOOLS=./tools/check_rows.c \
		./tools/does_matrix_exist.c \
		./tools/is_equal_size.c

ARITHMETIC_OPERATIONS=./arithmetic_operations/s21_sum_matrix.c \
						./arithmetic_operations/s21_sub_matrix.c \
						./arithmetic_operations/s21_mult_number.c \
						./arithmetic_operations/s21_mult_matrix.c

BASIC_OPERATIONS=../basic_operations/s21_eq_matrix.c \
					../basic_operations/s21_remove_matrix.c \
					../basic_operations/s21_create_matrix.c

SQUARE_MATRIX_OPERATIONS=../square_matrix_operations/s21_calc_complements.c \
							../square_matrix_operations/s21_determinant.c \
							../square_matrix_operations/s21_inverse_matrix.c
							../square_matrix_operations/s21_diagonal.c \
							../square_matrix_operations/s21_eigenvalue.c \
							../square_matrix_operations/s21_eigenvector.c \
							../square_matrix_operations/s21_orthogonal.c \
							../square_matrix_operations/s21_symmetric.c \
							../square_matrix_operations/s21_tarce.c

TRANSFORMATION=../transformation/s21_transpose.c

OBJ=$(TOOLS \
		ARITHMETIC_OPERATIONS \
		BASIC_OPERATIONS \
		SQUARE_MATRIX_OPERATIONS \
		TRANSFORMATION:.c=.o)

.PHONY: clean s21_matrix.a gcov_report clang test
all: $(OBJ)

s21_matrix.a:
	@$(CC) -c $(TOOLS) $(ARITHMETIC_OPERATIONS) $(BASIC_OPERATIONS) $(SQUARE_MATRIX_OPERATIONS) $(TRANSFORMATION)
	@ar rcs s21_matrix.a $(OBJ)

clang:
	@clang-format --style=Google -n ./tools/*.c ./tools/*.h
	@clang-format --style=Google -n ./arithmetic_operations/*.c ./tools/*.h
	@clang-format --style=Google -n ./basic_operations/*.c ./tools/*.h
	@clang-format --style=Google -n ./square_matrix_operations/*.c ./tools/*.h
	@clang-format --style=Google -n ./transformation/*.c ./tools/*.h

style:
	@clang-format --style=Google -i ./tools/*.c ./tools/*.h
	@clang-format --style=Google -i ./arithmetic_operations/*.c ./tools/*.h
	@clang-format --style=Google -i ./basic_operations/*.c ./tools/*.h
	@clang-format --style=Google -i ./square_matrix_operations/*.c ./tools/*.h
	@clang-format --style=Google -i ./transformation/*.c ./tools/*.h

#gcov_report:
#
#gcov_test:

clean:
	rm -rf s21_matrix.a *.o *.gcno *.gcda *.gcov *.gch test ./test.DSYM *.png *.html *.css *.info ./src
