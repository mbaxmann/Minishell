/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarlo <oscarlo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:46:42 by user42            #+#    #+#             */
/*   Updated: 2021/11/15 15:31:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_echo(char **av, char **envp, int fd1)
{
	int		i;
	char	new_line;

	i = 1;
	if (fd1 == -1)
		fd1 = STDOUT_FILENO;
	new_line = '\n';
	(void)envp;
	if (av[1] && !ft_strncmp("-n", av[1], 3))
	{
		new_line = '\0';
		i++;
	}
	while (av[i])
	{
		if ((i > 2 && av[i][0]) ||
			(new_line != '\0' && i == 2))
			write(fd1, " ", 1);
		write(fd1, av[i], ft_strlen(av[i]));
		i++;
	}
	write(fd1, &new_line, 1);
	return (0);
}
