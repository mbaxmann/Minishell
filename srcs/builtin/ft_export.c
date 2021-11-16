/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:15:10 by user42            #+#    #+#             */
/*   Updated: 2021/11/16 22:02:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_add(char ***envp, char *str)
{
	int		i;
	char	**envp_cp;
	char	**tmp;

	i = 0;
	tmp = *envp;
	while (tmp[i])
		i++;
	envp_cp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tmp[i])
	{
		envp_cp[i] = tmp[i];
		i++;
	}
	envp_cp[i] = ft_strdup(str);
	envp_cp[i + 1] = NULL;
	free(*envp);
	*envp = envp_cp;
}

static int	ft_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '=')
			return (0);
		i++;
	}
	return (1);
}

int	ft_export(char **av, char ***envp, int fd1)
{
	int	i;

	i = 1;
	if (fd1 == -1)
		fd1 = STDOUT_FILENO;
	if (!av[1])
		ft_export2(*envp, fd1);
	else
	{
		while (av[i])
		{
			if (!ft_valid(av[i]))
			{
				ft_putstr_fd("minishell: export: « ", fd1, 0);
				ft_putstr_fd(av[i], fd1, 0);
				ft_putstr_fd("» : invalid identifier\n", fd1, 0);
				return (1);
			}
			ft_add(envp, av[i]);
			i++;
		}
	}
	return (0);
}
