/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarlo <oscarlo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:47:08 by user42            #+#    #+#             */
/*   Updated: 2021/11/03 17:39:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*ft_relpath(void)
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

void	ft_cd(char **av)
{
	char *path;

	if (!av[1])
		path = ".";
	else
		path = av[1];
	if (chdir(path) == -1)
	{
		printf("cd: no such file or directory: %s\n", path);
	}
	path = ft_relpath();
	printf("%s\n", path);
	free(path);
}
