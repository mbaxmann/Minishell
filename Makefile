SRCS	=		srcs/builtin/ft_cd.c \
				srcs/builtin/ft_pwd.c \
				srcs/builtin/ft_echo.c \
				srcs/builtin/ft_env.c \
				srcs/builtin/ft_export.c \
				srcs/builtin/ft_export2.c \
				srcs/builtin/ft_unset.c \
				srcs/aux.c \
				srcs/ft_lst.c \
				srcs/ft_pipe.c \
				srcs/minishell.c \
				srcs/ft_envp.c \
				srcs/redirections.c \
				srcs/ft_sig_manage.c \
				srcs/ft_special_split.c \

OBJS    =       ${SRCS:.c=.o}

CC      =       clang -g

FLAGS   =       -Wall -Wextra -Werror -I/usr/local/opt/readline/include

NAME    =       minishell

RM      =       rm -rf

HEADER	=		include/minishell.h

LINK	=	-lft -lreadline -lncurses -L/usr/local/opt/readline/lib

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
