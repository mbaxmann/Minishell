/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:57:51 by user42            #+#    #+#             */
/*   Updated: 2021/11/16 21:57:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_is_ok(char *str)
{
	int	i;

	i = 0;
	if (!ft_strncmp(str, "?=", 2))
		return (0);
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	ft_env(char **av, char ***envp, int fd1)
{
	int		i;
	char	**envp2;

	i = 0;
	(void)av;
	envp2 = *envp;
	if (fd1 == -1)
		fd1 = STDOUT_FILENO;
	while (envp2[i])
	{
		if (ft_is_ok(envp2[i]))
			ft_putendl_fd(envp2[i], fd1);
		i++;
	}
	return (0);
}
