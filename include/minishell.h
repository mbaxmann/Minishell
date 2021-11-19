/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:32:48 by user42            #+#    #+#             */
/*   Updated: 2021/11/19 12:32:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/resource.h>
# include <sys/time.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <errno.h>
# include <term.h>

# include "ft_lst.h"
# include "ft_envp.h"
# include "builtin.h"
# include "ft_pipe.h"
# include "../libft/libft.h"

char	*ft_relpath(void);
int		check_redirections(t_list *new);
char	**erase_from_array(char **array, int element);
char	*ft_strjoin2(char const *s1, char const *s2);
void	ft_sig_manage(int mode);
int		ft_error(int errno_value);
int		ft_exec(t_list *cmd, char **envp);
char	**ft_special_split(char *s, char c);
void	clean_quotes(char **list, int d_q, int s_q);

#endif
