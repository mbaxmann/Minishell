/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:49:34 by mbaxmann          #+#    #+#             */
/*   Updated: 2019/11/09 13:17:59 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*tmp;
	char			*tmp2;

	tmp = dst;
	tmp2 = (char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		tmp[i] = tmp2[i];
		i++;
	}
	return (dst);
}
