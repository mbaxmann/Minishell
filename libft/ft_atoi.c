/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:35:00 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/13 18:15:58 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isminus(char c, int *i)
{
	if (c == '-')
	{
		(*i)++;
		return (-1);
	}
	else
	{
		(*i)++;
		return (1);
	}
}

int	ft_atoi(const char *str)
{
	int			i;
	int			minus;
	long int	res;

	i = 0;
	minus = 1;
	res = 0;
	while (str[i])
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		if (str[i] == '-' || str[i] == '+')
			minus = ft_isminus(str[i], &i);
		while (str[i] >= '0' && str[i] <= '9' && res * 10 < 2147483648)
			res = res * 10 + (str[i++] - '0');
		if ((res > 2147483648 || str[i] >= '0' && str[i] <= '9') && minus == -1)
			return (0);
		if ((res > 2147483647 || str[i] >= '0') && str[i] <= '9' && minus == 1)
			return (-1);
		return (res * minus);
	}
	return (res * minus);
}
