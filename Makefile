CC = cc
RM = rm -f
BUFFER_SIZE ?= 100
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=${BUFFER_SIZE}

SRCS = get_next_line.c get_next_line_utils.c
B_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
TEST_DIR = ./tests/

NAME = gnl

B_NAME = gnl_bonus

all: ${NAME}
	@echo "'gnl' Compiled Successfully"

${NAME}:	${SRCS}
					${CC} ${CFLAGS} $^ -o $@

bonus:		${B_NAME}

${B_NAME}: ${B_SRCS}
					${CC} ${CFLAGS} $^ -o $@
					@echo "'gnl_bonus' Compiled Successfully"

clean:
					${RM} *.o

fclean:		clean
					${RM} ${NAME} ${B_NAME}
					@make fclean -C $(TEST_DIR)

re:			fclean	all

re_bonus:	fclean	bonus

test_all:
					make a -C $(TEST_DIR)
test_m:
					make m -C $(TEST_DIR)
test_b:
					make b -C $(TEST_DIR)

.PHONY:	fclean clean all re bonus
