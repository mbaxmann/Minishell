/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:12:36 by mbaxmann          #+#    #+#             */
/*   Updated: 2019/11/11 16:18:05 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s1_bis;
	char	*s2_bis;

	i = 0;
	s1_bis = (char *)s1;
	s2_bis = (char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1_bis[i] != s2_bis[i])
			return ((unsigned char)s1_bis[i] - (unsigned char)s2_bis[i]);
		i++;
	}
	i--;
	return ((unsigned char)s1_bis[i] - (unsigned char)s2_bis[i]);
}
