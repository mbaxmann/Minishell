/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarlo <oscarlo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:14:40 by oscarlo           #+#    #+#             */
/*   Updated: 2021/11/12 15:41:06 by oscarlo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


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
	ft_putstr_fd("Sizes ", 2, 0);
	ft_putnbr_fd(aux, 2);
	ft_putstr_fd(" and ", 2, 0);
	ft_putnbr_fd(i, 2);
	ft_putendl_fd(array[element], 2);
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