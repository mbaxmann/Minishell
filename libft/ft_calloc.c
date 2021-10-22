/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:58:32 by mbaxmann          #+#    #+#             */
/*   Updated: 2019/11/08 14:36:26 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*res;

	i = 0;
	res = malloc(count * size);
	if (res == NULL)
		return (NULL);
	while (i < size * count)
	{
		*(char *)res = 0;
		i++;
		res++;
	}
	return (res - i);
}
