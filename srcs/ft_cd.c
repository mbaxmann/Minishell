/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarlo <oscarlo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:47:08 by user42            #+#    #+#             */
/*   Updated: 2021/10/27 21:04:05 by oscarlo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_cd(char **av)
{
	char *path;

	if (!av[1])
		path = "~/";
	else
		path = av[1];
	if (chdir(path) == -1)
	{
		printf("cd: no such file or directory: %s\n", path);
	}
	path = getcwd(NULL, 0);
	printf("%s\n", path);
	free(path);
}
