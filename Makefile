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

ARITHMETIC_OPERATIONS		=	./srcs/arithmetic_operations/sum_matrix.c \
								./srcs/arithmetic_operations/sub_matrix.c \
								./srcs/arithmetic_operations/mult_number.c \
								./srcs/arithmetic_operations/mult_matrix.c

BASIC_OPERATIONS	 		=	./srcs/basic_operations/eq_matrix.c \
								./srcs/basic_operations/delete_matrix.c \
								./srcs/basic_operations/create_matrix.c

SQUARE_MATRIX_OPERATIONS	=	./srcs/square_matrix_operations/complements.c \
								./srcs/square_matrix_operations/determinant.c \
								./srcs/square_matrix_operations/inverse.c

TRANSFORMATION				=	./srcs/transformation/transpose.c

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
	@clang-format --style=Google -n $(SRC_TEST) matrix.h

clang:
	@clang-format --style=Google -i $(SRC_TEST) matrix.h

clean:
	@rm -rf *.o *.gcno *.gcda *.gcov *.gch \
	test ./test.DSYM *.png *.html *.css *.info ./src \
	$(call rwildcard,.,*.o) cmd_line ./usr \
	$(call rwildcard,.,*.html)
