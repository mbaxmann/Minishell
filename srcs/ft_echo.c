/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:46:42 by user42            #+#    #+#             */
/*   Updated: 2021/10/27 19:16:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **av)
{
	int		i;
	char	new_line;

	i = 1;
	new_line = '\n';
	if (ac > 1 && !ft_strncmp("-n", av[1], 3))
	{
		new_line = '\0';
		i++;
	}
	while (i < ac)
	{
		if (i != 0)
			write(1, " ", 1);
		write(1, av[i], ft_strlen(av[i]));
		i++;
	}
	write(1, &new_line, 1);
	return (0);
}
