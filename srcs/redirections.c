/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarlo <oscarlo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:56:17 by olozano-          #+#    #+#             */
/*   Updated: 2021/11/12 15:59:05 by oscarlo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	take_redirection(t_list *new, char *arg)
{
	if (arg[0] == '>' && arg[1] == '>')
		new->fd1 = open(arg + 2, O_WRONLY | O_CREAT | O_APPEND, 0664);
	else if (arg[0] == '>')
		new->fd1 = open(arg + 1, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (new->fd1 == -1)
		return (0);
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
