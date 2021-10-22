/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:24:37 by mbaxmann          #+#    #+#             */
/*   Updated: 2019/11/08 14:30:49 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*tmp_dst;
	unsigned const char		*tmp_src;
	unsigned int			i;

	i = 0;
	tmp_dst = dst;
	tmp_src = src;
	while (i < (unsigned int)n)
	{
		if (tmp_src[i] != (unsigned char)c)
			tmp_dst[i] = tmp_src[i];
		else
		{
			tmp_dst[i] = tmp_src[i];
			i++;
			return (&(tmp_dst[i]));
		}
		i++;
	}
	return (NULL);
}
