/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:56:17 by olozano-          #+#    #+#             */
/*   Updated: 2021/11/15 21:49:55 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_error(int errno_value)
{
	ft_putendl_fd(strerror(errno_value), 2);
	return (0);
}

int	take_redirection(t_list *new, char *arg)
{
	if (arg[0] == '>')
	{
		if (arg[1] == '>') /// THIS NEEDS TO BE IMPLEMENTED STILL
			new->fd1 = open(arg + 2, O_CREAT | O_RDWR | O_APPEND, 0600);
		else
			new->fd1 = open(arg + 1, O_CREAT | O_RDWR | O_TRUNC, 0600);
		if (new->fd1 == -1)
			return (ft_error(errno));
	}
	else if (arg[0] == '<')
	{
		if (arg[1] == '<')
			new->fd2 = open(arg + 2, O_RDWR, 0600);
		else
			new->fd2 = open(arg + 1, O_RDWR, 0600);
		if (new->fd2 == -1)
			return (ft_error(errno));
	}
	return (1);
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
	char	*aux;

	i = 0;
	while (++i && new->arg && new->arg[i])
		if (new->arg[i][0] == '>' || new->arg[i][0] == '<')
		{
			if (redirect(new->arg[i]))
			{
				aux = ft_strjoin2(new->arg[i], new->arg[i + 1]);
				if (!take_redirection(new, aux))
					return (-42);
				new->arg = erase_from_array(new->arg, i + 1);
				free(aux);
			}
			else
				if (!take_redirection(new, new->arg[i]))
					return (-42);
			new->arg = erase_from_array(new->arg, i);
			return (1);
		}
	return (0);
}
