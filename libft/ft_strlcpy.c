/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:22:59 by mbaxmann          #+#    #+#             */
/*   Updated: 2019/11/11 16:28:43 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (!dstsize)
		return (ft_strlen(src));
	if ((ft_strlen(src) + 1) < dstsize)
	{
		while (i < (ft_strlen(src) + 1))
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		while (i < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i - 1] = '\0';
	}
	return (ft_strlen(src));
}
