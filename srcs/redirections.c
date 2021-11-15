/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:56:17 by olozano-          #+#    #+#             */
/*   Updated: 2021/11/11 15:55:41 by olozano-         ###   ########.fr       */
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

int	check_redirections(t_list *new)
{
	int		i;
	char	*aux;

	i = 0;
	while (++i && new->arg && new->arg[i])
		if (new->arg[0] == '>' || new->arg[0] == '<')
		{
			if (!strncmp(*index, "<", 2) || !strncmp(*index, "<<", 3)
				|| !strncmp(*index, ">", 2) || !strncmp(*index, ">>", 3))
			{
				aux = ft_strjoin(*index, *(index+1));
				ft_putnbr_fd(ft_strlen(aux), 2);
				ft_putstr_fd(aux, 2, 0);
				if (!take_redirection(new, aux))
					return (-42);
				(*(index + 1))[0] = 0;
				ft_putnbr_fd(ft_strlen(*(index+1)), 2);
				ft_putendl_fd(*(index+1), 2);
				free(aux);
			}
			else
				if (!take_redirection(new, *index))
					return (-42);
			ft_putnbr_fd(ft_strlen(new->arg), 2);
			ft_putstr_fd(*index, 2, 0);
			new->arg[0] = 0;
			ft_putnbr_fd(ft_strlen(new->arg), 2);
			ft_putendl_fd(*index, 2);
			return (1);
		}
	return (0);
}
