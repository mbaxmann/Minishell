/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:58:38 by mbaxmann          #+#    #+#             */
/*   Updated: 2019/11/09 14:21:19 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char *)s;
	while (i < n)
	{
		if ((unsigned char)s2[i] == (unsigned char)c)
			return (&s2[i]);
		i++;
	}
	return (NULL);
}
