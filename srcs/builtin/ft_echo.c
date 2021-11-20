/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:46:42 by user42            #+#    #+#             */
/*   Updated: 2021/11/20 14:14:17 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_echo(char **av, char ***envp, int fd1)
{
	int		i;
	char	new_line;
	int		written;

	i = 0;
	if (fd1 == -1 && envp)
		fd1 = STDOUT_FILENO;
	new_line = '\n';
	if (av[1] && !ft_strncmp("-n", av[1], 3))
		new_line = '\0';
	written = 0;
	while (av[++i])
	{
		if (written && av[i][0] != 127
				&& av[i - 1][ft_strlen(av[i - 1]) - 1] != '\n')
			write(fd1, " ", 1);
		if (av[i][0] != 127 && ft_strlen(av[i])
			&& (ft_strncmp("-n", av[i], 3) || written))
		{
			write(fd1, av[i], ft_strlen(av[i]));
			written++;
		}
	}
	write(fd1, &new_line, 1);
	return (0);
}
