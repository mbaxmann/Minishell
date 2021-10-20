OBJS    =       ${SRCS:.c=.o}

SRCS	=

CC      =       clang

FLAGS   =       -Wall -Wextra -Werror

NAME    =       minishell

RM      =       rm -rf

HEADER	=		include/minishell.h

all:    ${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:        ${OBJS}
		${CC} -o ${NAME} ${OBJS}

${OBJS}:		${HEADER}

clean:
	${RM} ${OBJS}

fclean:         clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
