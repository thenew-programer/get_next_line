CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=${BUFFER_SIZE}
BUFFER_SIZE ?= 100

SRCS = get_next_line.c get_next_line_utils.c

NAME = gnl

all: ${NAME}
	@echo "'gnl' Compiled Successfully"

${NAME}:	${SRCS}
					${CC} ${CFLAGS} $^ -o $@

clean:
					${RM} *.o

fclean:		clean
					${RM} ${NAME}

re:			fclean	all

.PHONY:	fclean clean all re
