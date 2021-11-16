/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:59:17 by user42            #+#    #+#             */
/*   Updated: 2021/11/16 22:10:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_pwd(char **av, char ***envp, int fd1)
{
	int		i;
	char	**envp2;

	i = 0;
	(void)av;
	envp2 = *envp;
	if (fd1 == -1)
		fd1 = STDOUT_FILENO;
	while (ft_strncmp(envp2[i], "PWD=", 4))
		i++;
	write(fd1, envp2[i] + 4, ft_strlen(envp2[i]) - 4);
	write(fd1, "\n", 1);
	return (0);
}
