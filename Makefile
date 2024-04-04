CC =	gcc
FLAGS =	-Wall -Wextra -Werror --std=c11
TEST_FLAGS = -fprofile-arcs -ftest-coverage

TOOLS						=	./srcs/tools/check_rows_columns.c \
								./srcs/tools/does_matrix_exist.c \
								./srcs/tools/is_equal_size.c \
								./srcs/tools/find_non_zero_diagonal_element.c \
								./srcs/tools/gauss_elimination.c \
								./srcs/tools/is_square_matrix.c \
								./srcs/tools/row_copy.c \
								./srcs/tools/swap_rows.c

ARITHMETIC_OPERATIONS		=	./srcs/arithmetic_operations/s21_sum_matrix.c \
								./srcs/arithmetic_operations/s21_sub_matrix.c \
								./srcs/arithmetic_operations/s21_mult_number.c \
								./srcs/arithmetic_operations/s21_mult_matrix.c

BASIC_OPERATIONS	 		=	./srcs/basic_operations/s21_eq_matrix.c \
								./srcs/basic_operations/s21_remove_matrix.c \
								./srcs/basic_operations/s21_create_matrix.c

SQUARE_MATRIX_OPERATIONS	=	./srcs/square_matrix_operations/s21_calc_complements.c \
								./srcs/square_matrix_operations/s21_determinant.c \
								./srcs/square_matrix_operations/s21_inverse_matrix.c

TRANSFORMATION				=	./srcs/transformation/s21_transpose.c

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
