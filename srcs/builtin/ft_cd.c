/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:47:08 by user42            #+#    #+#             */
/*   Updated: 2021/11/19 18:53:11 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_relpath(void)
{
	char	*home;
	char	*path;
	int		i;

	i = 0;
	home = getenv("HOME");
	path = getcwd(NULL, 0);
	while (path[i] == home[i])
		i++;
	home = ft_strdup(&path[i]);
	free(path);
	home = ft_strjoin(ft_strdup("~"), home);
	return (home);
}

static char	*ft_get_home(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "HOME=", 5))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

static void	ft_update_pwd(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PWD=", 4))
		{
			free(envp[i]);
			envp[i] = ft_strjoin(ft_strdup("PWD="), getcwd(NULL, 0));
			return ;
		}
		i++;
	}
}

int	ft_cd(char **av, char ***envp, int fd1)
{
	char	*path;

	(void)envp;
	(void)fd1;
	if (!av[1])
		path = ft_get_home(*envp);
	else
		path = av[1];
	if (chdir(path) == -1)
	{
		ft_putstr_fd("cd: no such file or directory: ", 2, 0);
		ft_putendl_fd(path, 2);
		return (1);
	}
	else
		ft_update_pwd(*envp);
	return (0);
}
