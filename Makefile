CC =	gcc
FLAGS =	-Wall -Wextra -Werror --std=c11
TEST_FLAGS = -fprofile-arcs -ftest-coverage

TOOLS						=	./tools/check_rows_columns.c \
								./tools/does_matrix_exist.c \
								./tools/is_equal_size.c \
								./tools/find_non_zero_diagonal_element.c \
								./tools/gauss_elimination.c \
								./tools/is_square_matrix.c \
								./tools/row_copy.c \
								./tools/swap_rows.c

ARITHMETIC_OPERATIONS		=	./arithmetic_operations/s21_sum_matrix.c \
								./arithmetic_operations/s21_sub_matrix.c \
								./arithmetic_operations/s21_mult_number.c \
								./arithmetic_operations/s21_mult_matrix.c

BASIC_OPERATIONS	 		=	./basic_operations/s21_eq_matrix.c \
								./basic_operations/s21_remove_matrix.c \
								./basic_operations/s21_create_matrix.c

SQUARE_MATRIX_OPERATIONS	=	./square_matrix_operations/s21_calc_complements.c \
								./square_matrix_operations/s21_determinant.c \
								./square_matrix_operations/s21_inverse_matrix.c

TRANSFORMATION				=	./transformation/s21_transpose.c

SRCS 		=	$(ARITHMETIC_OPERATIONS) $(BASIC_OPERATIONS) \
				$(SQUARE_MATRIX_OPERATIONS) $(TRANSFORMATION) $(TOOLS)

SRC_TEST 	= 	$(ARITHMETIC_OPERATIONS) $(BASIC_OPERATIONS) \
           		$(SQUARE_MATRIX_OPERATIONS) $(TRANSFORMATION) $(TOOLS) ./tests/tests.c

OBJS		=	$(SRCS:.c=.o)

rwildcard = $(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

.PHONY: clean s21_matrix.a gcov_report clang test format
all: $(OBJS) s21_matrix.a clean

s21_matrix.a: $(OBJS)
	@$(CC) -c $(FLAGS) $(SRCS)
	@ar rc $@ $(OBJS)
	@ranlib $@

test: $(SRC_TEST)
	@$(CC) -o $@ $(TEST_FLAGS) `pkg-config --cflags --libs check` $(SRC_TEST)
	@./test

gcov_report: test
	@gcov ./*.gcno -m
	@lcov -t "gcov_report" -o gcov_report.info -c -d .
	@genhtml -o ./ gcov_report.info
	@open ./index-sort-f.html

main:
	@$(CC) -o $@ $(SRCS) main.c

style:
	@clang-format --style=Google -n $(SRC_TEST) s21_matrix.h

clang:
	@clang-format --style=Google -i $(SRC_TEST) s21_matrix.h

clean:
	@rm -rf *.o *.gcno *.gcda *.gcov *.gch \
	test ./test.DSYM *.png *.html *.css *.info ./src \
	$(call rwildcard,.,*.o) cmd_line ./usr \
	$(call rwildcard,.,*.html)
