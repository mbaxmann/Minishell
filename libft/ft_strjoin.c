/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:21:47 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/13 17:48:42 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(char const *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	result = (char *)malloc((ft_size(s1) + ft_size(s2) + 1) * sizeof(char));
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
	if (s1)
		free((char *)s1);
	if (s2)
		free((char *)s2);
	return (result);
}
