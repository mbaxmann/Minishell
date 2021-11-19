/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:32:07 by user42            #+#    #+#             */
/*   Updated: 2021/11/19 01:52:23 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_exit(char **av, char ***envp, int fd1)
{
	int	num;
	(void)av;
	(void)envp;
	(void)fd1;
	num = ft_atoi(av[1]);
	if (!av[1])
		exit(0);
	if (!num)
	{
		if (ft_strncmp(av[1], "0", 2) && ft_strncmp(av[1], "+0", 2) 
			&& ft_strncmp(av[1], "-0", 2))
			exit(255);
		else if (!av[2])
			exit(0);
	}
	if (av[1] && av[2])
	{
		ft_putstr_fd("minishell: line 0: exit: ", 2, 0);
		ft_error(7);
		exit(1);
	}
	exit(num);
	return (0);
}
