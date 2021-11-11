/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:46:42 by user42            #+#    #+#             */
/*   Updated: 2021/11/10 18:14:14 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	*ft_echo(char **av, char **envp, int fd1)
{
	int		i;
	char	new_line;

	i = 1;
	new_line = '\n';
	(void)envp;
	if (av[1] && !ft_strncmp("-n", av[1], 3))
	{
		new_line = '\0';
		i++;
	}
	while (av[i])
	{
		if (i > 1)
			write(fd1, " ", 1);
		write(fd1, av[i], ft_strlen(av[i]));
		i++;
	}
	write(fd1, &new_line, 1);
	return (NULL);
}
