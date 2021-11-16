/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:47:08 by user42            #+#    #+#             */
/*   Updated: 2021/11/15 19:17:09 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

int	ft_cd(char **av, char **envp, int fd1)
{
	char *path;

	(void)envp;
	(void)fd1;
	if (!av[1])
		path = ".";
	else
		path = av[1];
	if (chdir(path) == -1)
	{
		ft_putstr_fd("cd: no such file or directory: ", STDOUT_FILENO, 0);
		ft_putendl_fd(path, STDOUT_FILENO);
		return (1);
	}
	return (0);
}
