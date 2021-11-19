/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:46:42 by user42            #+#    #+#             */
/*   Updated: 2021/11/19 00:34:00 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_echo(char **av, char ***envp, int fd1)
{
	int		i;
	char	new_line;
	int		written;

	i = 1;
	if (fd1 == -1)
		fd1 = STDOUT_FILENO;
	new_line = '\n';
	(void)envp;
	if (av[1] && !ft_strncmp("-n", av[1], 3))
		new_line = '\0';
	written = 0;
	while (av[i])
	{
		if (written && av[i][0] != 127)
			write(fd1, " ", 1);
		if (av[i][0] != 127 && ft_strlen(av[i]) && (ft_strncmp("-n", av[i], 3) || written))
		{
			write(fd1, av[i], ft_strlen(av[i]));
			written++;
		}
		i++;
	}
	write(fd1, &new_line, 1);
	return (0);
}
