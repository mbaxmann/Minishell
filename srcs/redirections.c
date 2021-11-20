/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:56:17 by olozano-          #+#    #+#             */
/*   Updated: 2021/11/20 01:33:58 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_error(int errno_value)
{
	ft_putstr_fd("ERROR :: ", 2, 0);
	ft_putendl_fd(strerror(errno_value), 2);
	return (0);
}

int	take_redirection(t_list *new, char *arg)
{
	int		ret;

	ret = 0;
	if (arg[0] == '>')
	{
		if (arg[1] == '>')
			new->fd1 = open(arg + 2, O_CREAT | O_RDWR | O_APPEND, 0600);
		else
			new->fd1 = open(arg + 1, O_CREAT | O_RDWR | O_TRUNC, 0600);
	}
	else if (arg[0] == '<')
	{
		if (arg[1] == '<')
		{
			new->fd2 = -42;
			new->aux = ft_strdup(arg + 2);
		}
		else
			new->fd2 = open(arg + 1, O_RDWR, 0600);
	}
	if ((arg[0] == '<' && new->fd2 == -1) || (arg[1] == '>' && new->fd1 == -1))
			ret = ft_error(errno);
	free(arg);
	return (ret);
}

int	redirect(char *str)
{
	if (!ft_strncmp(str, "<", 2) || !ft_strncmp(str, "<<", 3)
		|| !ft_strncmp(str, ">", 2) || !ft_strncmp(str, ">>", 3))
		return (1);
	return (0);
}

int	check_redirections(t_list *new)
{
	int		i;

	i = 0;
	while (new->arg && ++i && new->arg[i])
	{
		if (new->arg[i][0] == '>' || new->arg[i][0] == '<')
		{
			if (redirect(new->arg[i]))
			{
				if (!take_redirection(new, ft_strjoin2(new->arg[i],
							new->arg[i + 1])))
					return (-1);
				new->arg = erase_from_array(new->arg, i + 1);
			}
			else
				if (!take_redirection(new, new->arg[i]))
					return (-1);
			new->arg = erase_from_array(new->arg, i);
			i--;
		}
	}
	return (0);
}
