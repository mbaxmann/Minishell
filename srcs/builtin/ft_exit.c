/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:32:07 by user42            #+#    #+#             */
/*   Updated: 2021/11/19 20:09:32 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_say_and_go(char *str)
{
	ft_putstr_fd("minishell: line 0: ", 2, 0);
	ft_putstr_fd(str, 2, 0);
	ft_putendl_fd(": numeric argument required", 2);
	exit(255);
}

int	ft_exit(char **av, char ***envp, int fd1)
{
	int	num;

	if (av || envp || fd1)
		;
	num = ft_atoi(av[1]);
	if (!av[1])
		exit(0);
	if (!num)
	{
		if ((ft_strncmp(av[1], "0", 2) && ft_strncmp(av[1], "+0", 2)
				&& ft_strncmp(av[1], "-0", 2)))
			ft_say_and_go(av[1]);
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
