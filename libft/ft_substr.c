/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:52:50 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/13 17:55:05 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start || !len)
	{
		result = (char *)malloc(1 * sizeof(char));
		result[0] = '\0';
		return (result);
	}
	while (s[start + i] && i < len)
		i++;
	result = (char *)malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
