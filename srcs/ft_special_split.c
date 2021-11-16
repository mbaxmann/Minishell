/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarlo <oscarlo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:16:27 by olozano-          #+#    #+#             */
/*   Updated: 2021/11/15 23:38:03 by oscarlo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_words(char *str, char c)
{
	int i;
	int words;
	int first;

	if (!str)
		return (-1);
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
		}
		i++;
	}
	return (words);
}

static char	**first_alloc(char const *s, char c)
{
	int		words;
	char	**res;

	words = count_words((char*)s, c);
	if (!(res = malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	res[words] = NULL;
	return (res);
}

static int	size_word(char const *s, int i, char c)
{
	int j;

	j = 0;
	while (s[i + j] != c && s[i + j])
		j++;
	return (j);
}

char		*fill_it(char **res, char const *s, int *i, char c)
{
	char	*new_one;
	int j;

	new_one = malloc(sizeof(char) * (size_word(s, i, c) + 1));
	if (!new_one)
		return (NULL);
	j = 0;
	while (s[*i + j] != c && s[*i + j])
	{
		new_one[j] = s[*i + j];
		j++;
	}
	new_one[j] = '\0';
	words++;
	i = i + j - 1;
	return (new_one);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		words;
	char	**res;

	res = first_alloc(s, c);
	if (!s || !res)
		return (0);
	i = -1;
	words = 0;
	while (*(s + ++i))
	{
		if (s[i] != c)
		{
			res[words] = fill_it(res, s, &i, c);
		}
	}
	return (res);
}
