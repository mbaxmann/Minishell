/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olozano- <olozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:59:17 by user42            #+#    #+#             */
/*   Updated: 2021/11/10 18:14:12 by olozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	*ft_pwd(char **av, char **envp, int fd1)
{
	int	i;

	i = 0;
	(void)av;
	while (ft_strncmp(envp[i], "PWD=", 4))
		i++;
	write(fd1, envp[i] + 4, ft_strlen(envp[i]) - 4);
	write(fd1, "\n", 1);
	return (NULL);
}
