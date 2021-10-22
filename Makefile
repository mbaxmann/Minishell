OBJS    =       ${SRCS:.c=.o}

SRCS	=

CC      =       clang

FLAGS   =       -Wall -Wextra -Werror

NAME    =       minishell

RM      =       rm -rf

HEADER	=		include/minishell.h

LINK	=	-lft

LIB     =       libft/libft.a

LIB_PATH	=	-L ./libft/

all:    ${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:        ${OBJS}
		make -C libft
		${CC} ${LIB_PATH} -o ${NAME} ${OBJS} ${LINK}

${OBJS}:		${HEADER}

clean:
	make clean -C libft
	${RM} ${OBJS}

fclean:         clean
	make fclean -C libft
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
