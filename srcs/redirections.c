/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:56:17 by olozano-          #+#    #+#             */
/*   Updated: 2021/11/11 10:06:19 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	erase_arg(t_list *new, char *arg)
{
	char	**index;

	index = new->arg;
	while (index)
	{
		if (!ft_strncmp(*index, arg, ft_strlen(*index)))
		{
			ft_bzero(*index, ft_strlen(*index));
			return ;
		}
		index++;
	}
	return ;
}

int	take_redirection(t_list *new, char *arg)
{
	if (arg[0] == '>' && arg[1] == '>')
		new->fd1 = open(arg + 2, O_WRONLY | O_APPEND);
	else if (arg[0] == '>')
		new->fd1 = open(arg + 1, O_WRONLY | O_CREAT, 0664);
	if (new->fd1 == -1)
		return (0);
	return (1);
}

int	check_redirections(t_list *new)
{
	char	**index;

	if (!new->arg)
		return (-1);
	index = new->arg;
	while (*index)
	{
		if ((*index)[0] == '>' || (*index)[1] == '<')
		{
			if (!take_redirection(new, *index))
				return (-42);
			erase_arg(new, *index);
			return (1);
		}
		index++;
	}
	return (0);
}
