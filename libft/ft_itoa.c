/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:57:40 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/13 18:03:20 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse_tab(char *tab)
{
	int		i;
	int		size;
	char	*tr;

	i = 0;
	tr = (char *)malloc(sizeof(char) * (ft_strlen(tab) + 1));
	size = ft_strlen(tab);
	while (tab[i])
	{
		tr[size - 1 - i] = tab[i];
		i++;
	}
	tr[size] = '\0';
	i = 0;
	while (tr[i])
	{
		tab[i] = tr[i];
		i++;
	}
	tab[i] = '\0';
	free(tr);
}

int	ft_settr(int nbr, int x)
{
	if (x && nbr < 0)
		return (1);
	else if (x && nbr >= 0)
		return (0);
	if (!x && nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

void	ft_convert(char *res, int nbr, int pow, char m)
{
	int				i;
	unsigned int	tr;

	i = 0;
	if (m == 'd')
		tr = ft_settr(nbr, 0);
	else
		tr = (unsigned int)nbr;
	while (pow)
	{
		res[i] = (tr % 10) + 48;
		tr /= 10;
		i++;
		pow--;
	}
	if (nbr < 0 && m == '0')
	{
		res[i] = '-';
		res[i + 1] = '\0';
	}
	else
		res[i] = '\0';
	ft_reverse_tab(res);
}

int	ft_power(unsigned int tr)
{
	int	pow;

	pow = 0;
	while (tr)
	{
		tr /= 10;
		pow++;
	}
	return (pow);
}

char	*ft_itoa(int n, char m)
{
	int				x;
	unsigned int	tr;
	int				pow;
	char			*res;

	if (m == 'd')
		tr = ft_settr(n, 0);
	else
		tr = (unsigned int)n;
	if (n == 0)
	{
		res = (char *)malloc(sizeof(char) * 2);
		if (!res)
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	pow = ft_power(tr);
	x = ft_settr(n, 1);
	res = (char *)malloc(sizeof(char) * (pow + 1 + x));
	if (!res)
		return (NULL);
	ft_convert(res, n, pow, m);
	return (res);
}
