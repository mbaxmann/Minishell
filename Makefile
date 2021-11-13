SRCS	=		srcs/ft_cd.c srcs/aux.c srcs/ft_echo.c srcs/ft_lst.c srcs/ft_pipe.c srcs/minishell.c srcs/ft_envp.c srcs/ft_pwd.c srcs/redirections.c

OBJS    =       ${SRCS:.c=.o}

CC      =       clang -g

FLAGS   =       -Wall -Wextra -Werror

NAME    =       minishell

RM      =       rm -rf

HEADER	=		include/minishell.h

LINK	=	-lft -lreadline

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
