/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:15:10 by user42            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/18 23:07:33 by user42           ###   ########.fr       */
=======
/*   Updated: 2021/11/18 22:58:26 by olozano-         ###   ########.fr       */
>>>>>>> 9b46dd9ae451d8fe76ef6174fc53ffdee64fce9a
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
	envp_cp = (char **)malloc(sizeof(char *) * (i + 2));
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
		if (!ft_isalpha(str[i]) && str[i] != '=')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_replace(char **envp, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] && str[j] != '=')
		j++;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], str, j))
		{
			if (str[j] == '\0')
				return (1);
			free(envp[i]);
			envp[i] = ft_strdup(str);
			return (1);
		}
		i++;
	}
	return (0);
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
				ft_putstr_fd("minishell: export: « ", 2, 0);
				ft_putstr_fd(av[i], 2, 0);
				ft_putstr_fd("» : invalid identifier\n", 2, 0);
				return (1);
			}
			if (!ft_replace(*envp, av[i]))
				ft_add(envp, av[i]);
			i++;
		}
	}
	return (0);
}
