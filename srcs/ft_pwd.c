/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:59:17 by user42            #+#    #+#             */
/*   Updated: 2021/11/10 15:05:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	*ft_pwd(char **av, char **envp)
{
	int	i;

	i = 0;
	(void)av;
	while (ft_strncmp(envp[i], "PWD=", 4))
		i++;
	write(STDOUT_FILENO, envp[i] + 4, ft_strlen(envp[i]) - 4);
	write(STDOUT_FILENO, "\n", 1);
	return (NULL);
}
