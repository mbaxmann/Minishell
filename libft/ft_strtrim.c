/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:52:31 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/13 17:54:25 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lenstr(char const *s1)
{
	int	i;

	i = 0;
	if (s1 == NULL)
		return (0);
	while (s1[i])
		i++;
	return (i);
}

int	ft_is_set(char const *s1, char const *set, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 1;
	if (s1[i] == 0)
		k == -1;
	if (s1[i] == 0)
		i--;
	if (!set)
		return (0 + i);
	while (s1[i] && set[j])
	{
		if (s1[i] == set[j])
		{
			i += k;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_set_empty_str(void)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * 1);
	result[0] = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*result;

	i = 0;
	j = 0;
	result = NULL;
	if (!s1)
		return (NULL);
	len = ft_lenstr(s1);
	if (len == 0)
	{
		result = ft_set_empty_str();
		return (result);
	}
	j = ft_is_set(s1, set, 0);
	if (j == ft_lenstr(s1))
	{
		result = ft_set_empty_str();
		return (result);
	}
	i = ft_is_set(s1, set, ft_lenstr(s1));
	result = ft_substr(s1, j, i - j + 1);
	return (result);
}
