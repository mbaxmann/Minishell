/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:47:08 by user42            #+#    #+#             */
/*   Updated: 2021/11/11 12:43:15 by user42           ###   ########.fr       */
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

void	*ft_cd(char **av, char **envp, int fd1)
{
	char *path;

	(void)envp;
	if (fd1 == -1)
		fd1 = STDOUT_FILENO;
	if (!av[1])
		path = ".";
	else
		path = av[1];
	if (chdir(path) == -1)
	{
		ft_putstr_fd("cd: no such file or directory: ", fd1, 0);
		ft_putendl_fd(path, fd1);
	}
	path = ft_relpath();
	return (path);
}
