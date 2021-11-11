/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:32:48 by user42            #+#    #+#             */
/*   Updated: 2021/11/10 18:14:36 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <fcntl.h>
#include <signal.h>
#include <dirent.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <curses.h>
#include <errno.h>

#include "ft_lst.h"
#include "ft_envp.h"
#include "../libft/libft.h"

extern int	errno;

char	*ft_relpath(void);
void	*ft_echo(char **av, char **envp, int fd1);
void	*ft_cd(char **av, char **envp, int fd1);
void	*ft_pwd(char **av, char **envp, int fd1);
int		ft_pipe(t_list *cmd, char **envp);
int		check_redirections(t_list *new);

# endif
