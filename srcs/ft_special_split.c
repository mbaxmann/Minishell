/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:16:27 by olozano-          #+#    #+#             */
/*   Updated: 2021/11/18 23:53:16 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	size_word(char *s, int i, char c)
{
	int j;
	int k;

	j = 0;
	while (s[i + j] != c && s[i + j])
	{
		if (s[i + j] == '\"' || s[i + j] == '\'')
		{
			k = 1;
			while (s[i + j + k] && s[i + j + k] != s[i + j])
				k++;
			if (!s[i + j + k])
				return (-1);
			else
				j += k;
		}
		j++;
	}
	return (j);
}

static int	count_words(char *str, char c)
{
	int i;
	int words;
	int first;

	i = 0;
	first = 1;
	words = 0;
	while (str[i])
	{
		if (str[i] == c)
			first = 1;
		else
		{
			if (first)
				words++;
			first = 0;
			if (size_word(str, i, c) == -1)
				return (-1);
			i += size_word(str, i, c) - 1;
		}
		i++;
	}
	return (words);
}

static char	**first_alloc(char *s, char c)
{
	int		words;
	char	**res;

	words = count_words((char*)s, c);
	if (words == -1)
	{
		ft_putstr_fd("unclosed quote :: ", 2, 0);
		ft_error(22);
		return (NULL);
	}
	if (!(res = malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	res[words] = NULL;
	return (res);
}

char		*fill_it(char *s, int *i, char c)
{
	char	*new_one;
	int		j;
	int		size;

	size = size_word(s, *i, c);
	new_one = malloc(sizeof(char) * (size + 1));
	if (!new_one)
		return (NULL);
	j = 0;
	while (j < size)
	{
		new_one[j] = s[*i + j];
		j++;
	}
	new_one[size] = '\0';
	*i = *i + size;
	return (new_one);
}

char		**ft_special_split(char *s, char c)
{
	int		i;
	int		words;
	char	**res;

	res = first_alloc(s, c);
	if (!s || !res)
		return (NULL);
	i = -1;
	words = 0;
	while (*(s + ++i))
	{
		if (s[i] != c)
		{
			res[words] = fill_it(s, &i, c);
			words++;
			i += size_word(s, i, c) - 1;
		}
	}
	return (res);
}
