/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:46:42 by user42            #+#    #+#             */
/*   Updated: 2021/11/20 14:36:13 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	initialize_vars(int *i, char *new_line, int *written, int *sep)
{
	*i = 0;
	*written = 0;
	*sep = 0;
	*new_line = '\n';
}

int	ft_echo(char **av, char ***envp, int fd1)
{
	int		i;
	char	new_line;
	int		written;
	int		sep;

	initialize_vars(&i, &new_line, &written, &sep);
	if (fd1 == -1)
		fd1 = STDOUT_FILENO;
	(void)envp;
	if (av[1] && !ft_strncmp("-n", av[1], 3))
		new_line = '\0';
	while (av[++i])
	{
		if (written && av[i][0] != 127 && !sep)
			write(fd1, " ", 1);
		if (av[i][0] != 127 && ft_strlen(av[i])
			&& (ft_strncmp("-n", av[i], 3) || written))
		{
			sep = (av[i][ft_strlen(av[i]) - 1] == '\n');
			write(fd1, av[i], ft_strlen(av[i]));
			written++;
		}
	}
	write(fd1, &new_line, 1);
	return (0);
}
