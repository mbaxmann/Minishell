/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarlo <oscarlo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:21:19 by oscarlo           #+#    #+#             */
/*   Updated: 2021/11/03 16:39:47 by oscarlo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	shift_fd(char *file)
{
	(void) file;
	return ;
}

int	make_cmd(char *cmd, t_list **all_cmds)
{
	char	**separate;
	separate = ft_split(cmd, ' ');
	if (!strncmp("echo", separate[0], 5))
		ft_lst_push(all_cmds, &ft_echo, separate);
	else if (!strncmp("cd", separate[0], 3))
		ft_lst_push(all_cmds, &ft_cd, separate);
	else if (!strncmp("exit", separate[0], 6))
		exit(ft_atoi(separate[1]));
	else
	{
		ft_lst_push(all_cmds, NULL, separate);
		ft_putstr_fd("minishell: ", (*all_cmds)->fd2, 0);
		ft_putstr_fd((*all_cmds)->arg[0], (*all_cmds)->fd2, 0);
		ft_putstr_fd(": command not found\n", (*all_cmds)->fd2, 0);
		return (1);
	}
	return (0);
}

int	parse_second(char *str, t_list **all_cmds)
{
	char	**separate;
	int		i;

	separate = ft_split(str, '|');
	i = 0;
	while (separate[i])
	{
		if (make_cmd(separate[i], all_cmds))
			return (1);
		free(separate[i]);
		i++;
	}
	free(separate);
	if (i > 1)
		ft_pipe(*all_cmds);
	(*all_cmds)->funct((*all_cmds)->arg);
	return (42);
}

int	parse_first(char *str, t_list **all_cmds)
{
	char	**separate;
	int		i;

	separate = ft_split(str, ';');
	i = 0;
	while (separate[i])
	{
		parse_second(separate[i], all_cmds);
		free(separate[i]);
		ft_lst_free(*all_cmds);
		i++;
	}
	free(separate);
	return (42);
}

int	main(void)
{
	char	*str;
	t_list	*all_cmds;

	while (1)
	{
		all_cmds = NULL;
		str = readline("==> ");
		add_history(str);
		if (!str)
			return (1);
		if (!parse_first(str, &all_cmds))
		{
			free(str);
			return (1);
		}
		free(str);
	}
	return (0);
}
