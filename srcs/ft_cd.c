/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:47:08 by user42            #+#    #+#             */
/*   Updated: 2021/10/27 18:53:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **av)
{
	char *path;

	if (ac == 1)
		path = "~/";
	else
		path = av[1];
	if (chdir(path) == -1)
	{
		printf("cd: no such file or directory: %s\n", path);
		return (1);
	}
	path = getcwd(NULL, 0);
	printf("%s\n", path);
	free(path);
	return (0);
}
