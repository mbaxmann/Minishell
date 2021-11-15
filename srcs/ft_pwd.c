/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:59:17 by user42            #+#    #+#             */
/*   Updated: 2021/11/11 16:43:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_pwd(char **av, char **envp, int fd1)
{
	int	i;

	i = 0;
	(void)av;
	if (fd1 == -1)
		fd1 = STDOUT_FILENO;
	while (ft_strncmp(envp[i], "PWD=", 4))
		i++;
	write(fd1, envp[i] + 4, ft_strlen(envp[i]) - 4);
	write(fd1, "\n", 1);
	return (0);
}
