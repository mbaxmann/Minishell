/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:53:32 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/13 17:47:06 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while ((str[i] == c || str[i] == '\n') && str[i])
			i++;
		if (str[i])
			count++;
		while ((str[i] != c && str[i] != '\n') && str[i])
			i++;
	}
	return (count);
}

int	ft_get_len(char const *str, int *i, char c)
{
	int	len;

	len = 0;
	while ((str[*i] == c || str[*i] == '\n') && str[*i])
		(*i)++;
	while ((str[*i] != c && str[*i] != '\n') && str[*i])
	{
		(*i)++;
		len++;
	}
	return (len);
}

int	ft_fill(char **result, char const *str, int word_number, char c)
{
	int	i;
	int	k;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (j < word_number)
	{
		k = 0;
		len = ft_get_len(str, &i, c);
		i = i - len;
		result[j] = (char *)malloc(sizeof(char) * (len + 1));
		while (k < len)
		{
			while ((str[i] == c || str[i] == '\n') && str[i])
				i++;
			while ((str[i] != c && str[i] != '\n') && str[i])
				result[j][k++] = str[i++];
			result[j][k] = '\0';
		}
		j++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	int		word_number;
	int		j;
	char	**result;

	if (s == NULL)
	{
		result = (char **)malloc(sizeof(char *) * 1);
		if (!result)
			return (NULL);
		result[0] = NULL;
		return (result);
	}
	word_number = ft_count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (word_number + 1));
	if (!result)
		return (NULL);
	j = ft_fill(result, s, word_number, c);
	result[j] = NULL;
	return (result);
}
