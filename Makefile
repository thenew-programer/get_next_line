CC = cc
RM = rm -f
BUFFER_SIZE ?= 100
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=${BUFFER_SIZE}

SRCS = get_next_line.c get_next_line_utils.c
B_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c

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

re:			fclean	all

re_bonus:	fclean	bonus

.PHONY:	fclean clean all re bonus
