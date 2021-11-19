/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:14:40 by oscarlo           #+#    #+#             */
/*   Updated: 2021/11/19 10:19:57 by olozano-         ###   ########.fr       */
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
	new_one = (char **)malloc(aux * (sizeof (char *)));
	i = -1;
	aux = 0;
	while (array[++i])
		if (i != element)
			new_one[aux++] = ft_strdup(array[i]);
	new_one[aux] = malloc(sizeof(char));
	new_one[aux] = NULL;
	i = -1;
	while (array[++i])
		free(array[i]);
	free (array);
	return (new_one);
}
