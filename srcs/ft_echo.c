/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarlo <oscarlo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:46:42 by user42            #+#    #+#             */
/*   Updated: 2021/10/27 21:11:31 by oscarlo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_echo(char **av)
{
	int		i;
	char	new_line;

	i = 1;
	new_line = '\n';
	if (av[1] && !ft_strncmp("-n", av[1], 3))
	{
		new_line = '\0';
		i++;
	}
	while (av[i])
	{
		if (i > (new_line == '\0') + 1)
			write(1, " ", 1);
		write(1, av[i], ft_strlen(av[i]));
		i++;
	}
	write(1, &new_line, 1);
}
