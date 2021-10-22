/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:15:49 by mbaxmann          #+#    #+#             */
/*   Updated: 2019/11/09 14:17:45 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src2;
	char	*dst2;
	size_t	i;

	i = -1;
	src2 = (char *)src;
	dst2 = (char *)dst;
	if ((dst == NULL && src == NULL) || len == 0)
		return (dst);
	if (src < dst)
	{
		while (++i < len)
			dst2[len - 1 - i] = src2[len - 1 - i];
	}
	else if (dst < src)
	{
		while (++i < len)
			dst2[i] = src2[i];
	}
	return (dst2);
}
