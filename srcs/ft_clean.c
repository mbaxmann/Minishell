/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:21:42 by olozano-          #+#    #+#             */
/*   Updated: 2021/11/19 16:15:54 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	quotable(char c, int s_q, int d_q)
{
	if ((c != '\'' && c != '\"' && c != '\\')
		|| ((c == '\'' && d_q) || (c == '\"' && s_q))
		|| ((s_q || d_q) && c == '\\'))
		return (1);
	return (0);
}

int	remove_quotes(char **str, int size, int s_q, int d_q)
{
	int		i;
	char	*aux;

	aux = (char *)malloc (sizeof (char) * (size + 1));
	if (!aux)
		return (ft_error(errno) - 250);
	i = 0;
	size = 0;
	while ((*str)[i])
	{
		if (quotable((*str)[i], s_q, d_q))
			aux[size++] = (*str)[i];
		else
		{
			d_q = (d_q + (*str)[i] == '\"') % 2;
			s_q = (s_q + (*str)[i] == '\'') % 2;
		}
		i++;
	}
	aux[size] = 0;
	free(*str);
	*str = aux;
	return (size);
}

int	clean_n(char **list, int yes, int i)
{
	int	j;

	if (ft_strncmp("echo", list[0], 5) || !list[1])
		return (0);
	while (*list + ++i && yes)
	{
		yes = 0;
		j = 0;
		while (list[i][j] == '\"' || list[i][j] == '\'')
			j++;
		if (ft_strncmp("-n", list[i] + j, 2))
			continue ;
		while (list[i][++j] == 'n')
			;
		while (list[i][j] == '\"' || list[i][j] == '\'')
			j++;
		if (list[i][j])
			continue ;
		free(list[i]);
		list[i] = ft_strdup("-n");
		if (i > 1)
			list[i][0] = 127;
		yes = 1;
	}
	return (yes);
}

void	clean_quotes(char **list, int d_q, int s_q)
{
	int	i;
	int	j;
	int	q;

	i = -1;
	while (list[++i])
	{
		q = 0;
		d_q = 0;
		s_q = 0;
		j = -1;
		while (list[i][++j] && list[i][0] != 127)
		{
			if (quotable(list[i][j], s_q, d_q))
				q++;
			else
			{
				d_q = (d_q + list[i][j] == '\"') % 2;
				s_q = (s_q + list[i][j] == '\'') % 2;
			}
		}
		if (q != j)
			if (remove_quotes(list + i, q, 0, 0) < 0)
				return ;
	}
}
