/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:14:40 by oscarlo           #+#    #+#             */
/*   Updated: 2021/11/19 00:35:02 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		remove_quotes(char **str, int size, int s_q, int d_q)
{
	int		i;
	char	*aux;

	aux = (char*)malloc (sizeof (char) * (size + 1));
	if (!aux)
		return (ft_error(errno) - 250);
	i = 0;
	size = 0;
	while ((*str)[i])
	{
		if (((*str)[i] != '\'' && (*str)[i] != '\"' && (*str)[i] != '\\') ||
			(((*str)[i] == '\'' && d_q) || ((*str)[i] == '\"' && s_q))
			|| ((s_q || d_q) && (*str)[i] == '\\'))
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

int	clean_n(char **list, int yes)
{
	int	i;
	int	j;

	if (ft_strncmp("echo", list[0], 5) || !list[1])
		return (0);
	i = 0;
	while (*list + ++i && yes)
	{
		yes = 0;
		j = 0;
		while (list[i][j] == '\"' || list[i][j] == '\'')
			j++;
		if (ft_strncmp("-n", list[i] + j, 2))
			continue ;
		j++;
		while (list[i][j] == 'n')
			j++;
		while (list[i][j] == '\"' || list[i][j] == '\'')
			j++;
		if (list[i][j])
			continue ;
		free(list[i]);
		list[i] = ft_strdup("-n");
		ft_putstr_fd(list[i], 2, 0);
		ft_putendl_fd("--CLEANED", 2);
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
	int q;
	int	previous;

	i = 0;
	previous = 0;
	while (list[i])
	{
		q = 0;
		d_q = 0;
		s_q = 0;
		j = 0;
		while (list[i][j])
		{
			if ((list[i][j] != '\'' && list[i][j] != '\"' && list[i][j] != '\\') ||
			((list[i][j] == '\'' && d_q) || (list[i][j] == '\"' && s_q))
			|| ((s_q || d_q) && list[i][j] == '\\'))
				q++;
			else
			{
				d_q = (d_q + list[i][j] == '\"') % 2;
				s_q = (s_q + list[i][j] == '\'') % 2;
			}
			j++;
		}
		if (q != j)
			if (remove_quotes(list + i, q, 0, 0) < 0)
				return ;
		i++;
	}
}

int	ft_size2(char const *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	result = (char *)malloc((ft_size2(s1) + ft_size2(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char	**erase_from_array(char **array, int element)
{
	int		aux;
	int		i;
	char	**new_one;

	if (!array)
		return (NULL);
	aux = 0;
	while (array[aux])
		aux++;
	new_one = (char**)malloc(aux * (sizeof (char*)));
	i = 0;
	aux = 0;
	while (array[i])
	{
		if (i != element)
		{
			new_one[aux] = ft_strdup(array[i]);
			aux++;
		}
		i++;
	}
	new_one[aux] = malloc(sizeof(char));
	new_one[aux] = NULL;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free (array);
	return (new_one);
}